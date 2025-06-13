#if __cplusplus < 201700L
#error "C++17 required"
#endif

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>
#include <deque>
#include <cstdlib>
#include <cstddef>
#include <mutex>
#include <optional>

// 块类型有8种，但是这里包含了0:Unknow
constexpr int BlockTypeVariantCount = 9;
// 四种旋转类型
constexpr int BlockRotationCount = 4;
// 因为块一行一列不会超过4,使用我们可以用 4*4 16比特
// 压缩一个块，这里不携带偏移信息，但是包含了旋转信息
using ZipBlock = uint16_t;
// 一行只有10列，所以我们也可以压缩为一个10比特的数
// 向上取整，这里用来 u16
using LineMask = uint16_t;

// 你知道的，一行只有10列
constexpr LineMask FULL = 0b1'111'111'111;
// 你又知道一遍，一行只有10列了
constexpr int ColumnBound = 10;
// 我们预留了4行的空行，用于简化代码和死亡检测
constexpr int BlockBound = 4;
// 主要的地图只有18行
constexpr int LineBound = 18;
// 多加了一行全1的地面，简化碰撞
constexpr int ExtraLine = 1;

// 块的内部表示
using BlockMask = std::array<LineMask, BlockBound>;
// 地图的内部表示
// 0 -> 全1的碰撞检测层
// 1 - 18 实际能放的地方
// 19 20 21 22 预留的为块放置的地方
using MapMask = std::array<LineMask, LineBound + BlockBound + ExtraLine>;

class Block;
class BackMap;
class UserController;
// 方块们的类型
enum class BlockType : uint8_t {
    One = 1,
    Two = 2,
    Corner = 3,
    Square = 4,
    LeftL = 5,
    RightL = 6,
    Column = 7,
    Cross = 8,
};

// clang-format off
static constexpr ZipBlock PreProcessedBlocks[BlockTypeVariantCount][BlockRotationCount] = {
    {0, 0, 0, 0},
    {1, 1, 1, 1},
    {17, 3, 17, 3},
    {19, 35, 50, 49},
    {51, 51, 51, 51},
    {547, 116, 785, 23},
    {275, 71, 802, 113},
    {4369, 15, 4369, 15},
    {626, 626, 626, 626}
};
// clang-format on

// 该函数用于可视化一行
// 用于调试
std::string readable(LineMask mask, char color = 'H') {
    std::string result(ColumnBound, '.');
    for (int i = ColumnBound - 1; i >= 0; --i) {
        if (mask & 1) {
            result[i] = color;
        }
        mask >>= 1;
    }
    return result;
}

#if __cplusplus >= 202300L
#include <print>
std::string _block_type_as_str(BlockType type) {
    static constexpr std::string _name_list[BlockTypeVariantCount] = {
        "Unknown", "One", "Two", "Corner", "Square", "LeftL", "RightL", "Column", "Cross",
    };
    return _name_list[(int)type];
}
#endif

using LineArray = std::array<bool, ColumnBound>;
class LineProxy {
    friend Block;
    friend BackMap;
    LineMask const& ref;
    LineProxy(LineMask const& ref): ref(ref) {}
public:
    operator LineArray() const {
        LineArray a;
        for(int i = 0; i < ColumnBound;++i) {
            a[i] = this->operator[](i);
        } 
        return a;
    }
    bool operator[](int i) const {
        return (bool)((ref >> (ColumnBound - i - 1)) & 1);
    }
};

// 基本方块
class Block {
    friend BackMap;
    friend UserController;
    BlockType btype;
    BlockMask mask;
    int rotation = 0;
    int x = 0;

    Block(BlockType type, int rotation = 0) : btype(type), rotation(rotation % BlockRotationCount) {
        (rotation += BlockRotationCount) %= BlockRotationCount;
        std::fill(mask.begin(), mask.end(), 0);
        do_unzip_on(type, rotation, mask);
    }
    // 将预压缩的方块解压到BlockMask中
    static void do_unzip_on(BlockType tp, int rotation, BlockMask& mask) {
        ZipBlock blk = PreProcessedBlocks[(int)tp][rotation];
        for (int i = 0; i < BlockBound; ++i) {
            mask[i] = blk & 0b1111;
            blk >>= BlockBound;
        }
    }
    // 最高位是哪个比特呢...
    static int hbit(LineMask mask) {
        return mask == 0 ? -1 : std::__lg(mask);
    }
    // 最低位是哪个比特呢...
    static int lbit(LineMask mask) {
        mask = mask & -mask;
        return mask == 0 ? 10 : std::__lg(mask);
    }
    void sent() const {
        std::cout << (int)btype << " " << rotation << " " << x << std::endl;
    }

    // 该方块最左端的下标
    int lbound_inner() const {
        int res = -1;
        for (int i = 0; i < BlockBound; ++i) {
            res = std::max(res, hbit(mask[i]));
        }
        return res;
    }
    // 该方块最右端的下标
    int rbound_inner() const {
        int res = 10;
        for (int i = 0; i < BlockBound; ++i) {
            res = std::min(res, lbit(mask[i]));
        }
        return res;
    }

    int move_inner(int dx) {
        int left = lbound_inner();
        int right = rbound_inner();
        // [0,10)
        if (left + dx >= 10 || right + dx < 0)
            return false;
        x += dx;
        if (dx > 0) {
            for (int i = 0; i < BlockBound; ++i) {
                mask[i] <<= dx;
            }
        } else {
            dx = -dx;
            for (int i = 0; i < BlockBound; ++i) {
                mask[i] >>= dx;
            }
        }
        return true;
    }
public:
    // 右旋90度然后复位
    void rotate(int step = 1) {
        rotation = (rotation + step) % BlockRotationCount;
        do_unzip_on(btype, rotation, mask);
        x = 0;
    }
    void rotate_as(int r = 0) {
        rotation = r % BlockRotationCount;
        do_unzip_on(btype, rotation, mask);
        x = 0;
    }
    // 该方块最左端的下标
    int lbound() const {
        return ColumnBound - 1 - lbound_inner();
    }
    // 该方块最右端的下标
    int rbound() const {
        return ColumnBound - 1 - rbound_inner();
    }
    BlockType type() const {
        return btype;
    }
    Block remake_with(int r = 0) const {
        Block new_b {*this};
        new_b.rotate_as(r);
        return new_b;
    }
    // 祥，移动.
    // 向左移动 dx, 当且仅当没有冒出10列约束时返回 true
    bool move(int dx) {
        return move_inner(-dx);
    }
    // 产生一个对应类型对应旋转方式的块
    static Block make(BlockType type, int rotation = 0) {
        return Block(type, rotation);
    }

    int get_rotation() const {
        return rotation;
    }
    int get_x() const {
        return -x;
    }
    
    LineProxy operator[](int i) const {
        return LineProxy(mask[i]);
    }
};

class BackMap {
    friend Block;
    friend UserController;
    MapMask plain;
    int score = 0;
    static constexpr int bonus[] = {0, 1, 3, 6, 10};
    bool alive = true;
    bool is_preview = false;

    int remove_detect() {
        int h = 1, removed = 0;
        for (int cur = 1; cur < LineBound + ExtraLine + BlockBound; ++cur) {
            if (plain[cur] == FULL) {
                plain[cur] = 0;
                ++removed;
            }

            if (plain[h] != 0) {
                ++h;
                continue;
            }

            plain[h] = plain[cur];
            plain[cur] = 0;
            if (plain[h] != 0) {
                ++h;
                continue;
            }
        }
        score += bonus[removed];
        return removed;
    }

    bool alive_detect() {
        int h = LineBound + ExtraLine;
        for (int i = 0; i < BlockBound; ++i) {
            alive = alive && (plain[h + i] == 0);
        }
        return alive;
    }
    void grow(LineMask mask) {
        mask &= FULL;
        assert(mask != FULL);
        if (!alive) {
            return;
        }

        for (int i = LineBound + BlockBound; i > 1; --i) {
            plain[i] = plain[i - 1];
        }
        plain[1] = mask;
        alive = alive_detect();
    }

    BackMap() {
        plain.fill(0);
        plain[0] = FULL;
    }
    // 确认下落
    int assume(Block const& block) {
        if (!alive) {
            return 0;
        }
        if (!is_preview) {
            block.sent();
        }
        int h = LineBound + ExtraLine;
        // 检测碰撞
        for (; h > 0; --h) {
            bool hit = false;
            for (int i = 0; i < BlockBound; ++i) {
                hit = hit || ((plain[h + i] & block.mask[i]) != 0);
            }
            if (hit) {
                break;
            }
        }
        ++h;
        // 放置方块
        for (int i = 0; i < BlockBound; ++i) {
            plain[h + i] |= block.mask[i];
        }
        // 消除检测
        int removed = remove_detect();
        // 存活检测
        alive = alive_detect();
        return removed;
    }
public:
    LineProxy operator[](int i) const {
        return LineProxy(plain[i]);
    }
    
    // 我...现在多少分呢
    int current_score() const {
        return score;
    }
    // 假如我下落这个块，会发生什么？
    BackMap preview(Block const& block) const {
        BackMap ret{*this};
        ret.is_preview = true;
        ret.assume(block);
        return ret;
    }
    BackMap preview_rc(Block const& block, int & removed_count) const {
        BackMap ret{*this};
        ret.is_preview = true;
        removed_count = ret.assume(block);
        return ret;
    }
    
    // 我...现在还活着吗？
    bool is_alive() const {
        return alive;
    }
    // 最高层
    int max_layer() const {
        for(int i = 22; ; --i) {
            if (plain[i] != 0) {
                return i;
            }
        }
    }
};

class BlockList {
    friend UserController;
    std::deque<BlockType> types;
    BlockList(): types() {}
    void update() {
        int n = 0;
        std::cin >> n;
        int t;
        for (int i = 0; i < n; ++i) {
            std::cin >> t;
            types.emplace_back((BlockType)t);
        }
    }
    // 以rotation旋转方式拿出下一个块
    Block next_with(int rotation = 0) {
        BlockType t = types.front();
        types.pop_front();
        return Block::make(t, rotation);
    }
    void pop() {
        types.pop_front();
    }
    public:

    // 偷看第i块的类型
    BlockType peek(int i = 0) const {
        return types.at(i);
    }

    size_t size() const {
        return types.size();
    }

    Block operator[](int i) const {
        return Block::make(peek(i));
    }
};

class UserController {
    bool reset = false;
    inline static bool only_one = false;
    inline static std::mutex mtx = {};
    BackMap playground;
    BlockList blocklist;
    std::optional<Block> unctrlb = std::nullopt;
    void do_reset() {
        playground = BackMap();
        blocklist = BlockList();
        reset = false;
        // std::cout << "0 0 0" << std::endl;
    }
    bool update_inner() {
        reset = reset || !playground.is_alive();
        if (reset) {
            reason = "";
            do_reset();
        }
        unctrlb = std::nullopt;
        int n = 0, mask;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            std::cin >> mask;
            playground.grow(mask);
        }
        blocklist.update();
        std::cin >> n;
        // 0xh1h2h3
        // h1 -> 标志位
        //  0: 无事发生
        //  1: 不受控
        //  2: 结束
        // h2 -> 旋转方向
        // h3 -> 偏移距离
        mask = n >> (2 * 4);
        if (mask == 0) {
            if (reset) {
                reason = "Reset";
            }
            return !reset;
        }
        if (mask == 0xF) {
            reset = true;
            reason = "0xF";
            return false;
        }
        assert(mask == 0x1);
        mask = (n >> 4) & 0xF;
        Block b = blocklist.next_with(mask);
        b.move_inner(n & 0xF);
        unctrlb = b;
        playground.is_preview = true;
        playground.assume(b);
        playground.is_preview = false;
        reset = !playground.is_alive();
        if (reset) {
            reason = "Die";
        }
        return !reset;
    }
public:
    UserController() : playground(), blocklist() {
        if (only_one) {
            throw "Man What Can I Say";
        }
        mtx.lock();
        if (only_one) {
            mtx.unlock();
            throw "Man What Can I Say";
        }
        only_one = true;
        mtx.unlock();
    }
    bool is_finished() const {
        return reset;
    }
    std::string reason;
    // 从输入更新状态
    bool update() {
        bool f = update_inner();
        if (!f) {
            std::cout << "0 0 0" << std::endl;
        } 
        return f;
    }
    BlockList const& blocks() const {
        return blocklist;
    }
    BackMap const& map() const {
        return playground;
    }
    
    bool is_last_uc() const {
        return unctrlb.has_value();
    }

    std::optional<Block>const& ucblock() const {
        return unctrlb;
    }
    
    void operator << (Block const & b) {
        blocklist.pop();
        playground.assume(b);
    }
};

struct Game {
    BackMap const&map;
    BlockList const&blocks;
    std::optional<Block>const& ucblock;
    Block once_place();
    Game(UserController const&ctl) : map(ctl.map()),blocks(ctl.blocks()),ucblock(ctl.ucblock()) {
    }
};

/* 你可以更改这行以下的代码们 */

/* 你可以更改这行以下的代码们 */
#include <cmath>
#include <limits>

// 评估参数权重（根据实际测试优化）
constexpr int LANDING_HEIGHT_WEIGHT = -45;
constexpr int ROW_TRANSITIONS_WEIGHT = -32;
constexpr int COL_TRANSITIONS_WEIGHT = -93;
constexpr int HOLES_WEIGHT = -79;
constexpr int WELLS_WEIGHT = -34;
constexpr int LINE_SCORE_WEIGHT = 34;

// 辅助函数：计算行变换次数
int calculateRowTransitions(const BackMap& map) {
    int transitions = 0;
    for (int y = 1; y <= LineBound; ++y) {
        bool prev = true; // 左侧虚拟墙
        for (int x = 0; x < ColumnBound; ++x) {
            bool current = map[y][x];
            if (current != prev) transitions++;
            prev = current;
        }
        if (prev != true) transitions++; // 右侧虚拟墙
    }
    return transitions;
}

// 辅助函数：计算列变换次数
int calculateColTransitions(const BackMap& map) {
    int transitions = 0;
    for (int x = 0; x < ColumnBound; ++x) {
        bool prev = true; // 顶部虚拟墙
        for (int y = 1; y <= LineBound; ++y) {
            bool current = map[y][x];
            if (current != prev) transitions++;
            prev = current;
        }
        if (prev != true) transitions++; // 底部虚拟墙
    }
    return transitions;
}

// 辅助函数：计算空洞数量
int calculateHoles(const BackMap& map) {
    int holes = 0;
    for (int x = 0; x < ColumnBound; ++x) {
        bool hasBlock = false;
        for (int y = LineBound; y >= 1; --y) {
            bool filled = map[y][x];
            if (filled) {
                hasBlock = true;
            } else if (hasBlock) {
                holes++;
            }
        }
    }
    return holes;
}

// 辅助函数：计算井深
int calculateWells(const BackMap& map) {
    int wells = 0;
    for (int x = 0; x < ColumnBound; ++x) {
        int depth = 0;
        for (int y = 1; y <= LineBound; ++y) {
            bool left = (x == 0) ? true : map[y][x-1];
            bool right = (x == ColumnBound-1) ? true : map[y][x+1];
            bool current = map[y][x];
            
            if (!current && left && right) {
                depth++;
            } else {
                wells += depth * (depth + 1) / 2;
                depth = 0;
            }
        }
        wells += depth * (depth + 1) / 2;
    }
    return wells;
}

Block Game::once_place() {
    Block best_block = blocks[0];
    double best_score = -std::numeric_limits<double>::infinity();
    int best_priority = std::numeric_limits<int>::max();

    // 遍历所有可能的旋转状态
    for (int rotation = 0; rotation < BlockRotationCount; ++rotation) {
        Block rotated_block = blocks[0].remake_with(rotation);
        
        // 计算可移动范围
        int max_left = rotated_block.lbound();
        int max_right = ColumnBound - rotated_block.rbound() - 1;
        
        // 遍历所有可能的水平位置
        for (int dx = -max_left; dx <= max_right; ++dx) {
            Block candidate = rotated_block;
            if (!candidate.move(dx)) continue;

            // 生成预览地图
            int lines_cleared;
            BackMap preview = map.preview_rc(candidate, lines_cleared);
            
            // 死亡检测
            if (!preview.is_alive()) continue;
            
            // 高度检测（18层限制）
            if (preview.max_layer() > LineBound) continue;

            // 计算评估参数
            int landing_height = preview.max_layer();
            int row_trans = calculateRowTransitions(preview);
            int col_trans = calculateColTransitions(preview);
            int holes = calculateHoles(preview);
            int wells = calculateWells(preview);
            
            // 计算得分
            int line_score = lines_cleared * LINE_SCORE_WEIGHT;
            double total_score = 
                landing_height * LANDING_HEIGHT_WEIGHT +
                line_score +
                row_trans * ROW_TRANSITIONS_WEIGHT +
                col_trans * COL_TRANSITIONS_WEIGHT +
                holes * HOLES_WEIGHT +
                wells * WELLS_WEIGHT;

            // 计算操作优先级（移动步数 + 旋转次数）
            int priority = abs(dx) * 100 + rotation;

            // 更新最佳选择
            if (total_score > best_score || 
               (total_score == best_score && priority < best_priority)) {
                best_score = total_score;
                best_priority = priority;
                best_block = candidate;
            }
        }
    }

    return best_block;
}

/* 但是不要修改 main 函数 */

/* 但是不要修改 main 函数 */

int main() {
    UserController systemctl;
    for(;;) {
        Game game(systemctl);
        while (systemctl.update()) {
            systemctl << game.once_place();
        }
    }
}