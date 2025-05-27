#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> digits;  // 存储数字的每一位
    unordered_map<string, int> memo;  // 存储中间结果

    // 将数字拆成每一位并存储到 digits 中
    void get_digits(int x) {
        digits.clear();
        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
        reverse(digits.begin(), digits.end());
    }

    // 递归函数，用来计算符合条件的数字个数
    int dfs(int pos, int pre, bool has_bad, bool is_limit) {
        if (pos == digits.size()) {
            return has_bad ? 0 : 1;
        }

        // 使用缓存减少重复计算
        string key = to_string(pos) + "," + to_string(pre) + "," + to_string(has_bad) + "," + to_string(is_limit);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        int res = 0;
        int max_d = is_limit ? digits[pos] : 9;
        
        for (int d = 0; d <= max_d; ++d) {
            bool next_has_bad = has_bad;
            int next_pre = pre;

            // 判断是否包含坏数
            if (!has_bad) {
                if (d == 4) {
                    next_has_bad = true;
                } else if (pre == 6 && d == 2) {
                    next_has_bad = true;
                }
            }

            // 更新前一位数字，处理前导零
            if (pre == -1 && d != 0) {
                next_pre = d;
            } else {
                next_pre = d;
            }

            bool new_is_limit = is_limit && (d == max_d);
            res += dfs(pos + 1, next_pre, next_has_bad, new_is_limit);
        }

        memo[key] = res;  // 缓存结果
        return res;
    }

public:
    // 计算从 1 到 x 中符合条件的数字个数
    int calc(int x) {
        if (x < 0) return 0;
        get_digits(x);
        memo.clear();  // 清空缓存
        return dfs(0, -1, false, true);
    }
};

int main() {
    Solution solution;
    int L, R;
    
    while (cin >> L >> R) {
        if (L == 0 && R == 0) {
            break;
        }
        cout << solution.calc(R) - solution.calc(L - 1) << endl;
    }

    return 0;
}
