#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// 使用结构体存储文件，方便排序
struct File {
    int w, v;
};

bool cmp(File a, File b) {
    return a.w < b.w; // 按文件大小从小到大排序
}

int n, S;
long long p; 
File files[1005];
long long dp[1005]; // dp[j] 表示容量为 j 时的最大价值

// 校验函数：如果接口大小为 limit，能否凑出价值 p
bool check(int limit) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        // 核心：只处理大小不超过接口限制的文件
        if (files[i].w > limit) break; 
        
        // 标准 0/1 背包转移方程
        for (int j = S; j >= files[i].w; j--) {
            dp[j] = max(dp[j], dp[j - files[i].w] + files[i].v);
            // 提前优化：如果已经达到目标价值，直接返回 true
            if (dp[j] >= p) return true;
        }
    }
    return dp[S] >= p;
}

int main() {
    // 提高输入输出效率
    ios::sync_with_stdio(false);
    cin.tie(0);

    if (!(cin >> n >> p >> S)) return 0;

    for (int i = 0; i < n; i++) {
        cin >> files[i].w >> files[i].v;
    }

    // 1. 预处理：按大小排序，方便 check 函数
    sort(files, files + n, cmp);

    // 2. 二分答案：查找最小的满足条件的接口大小
    int l = 1, r = 1000, ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;    // 这个接口可以，尝试找更小的
            r = mid - 1;
        } else {
            l = mid + 1;  // 这个接口不行，必须买更大的
        }
    }

    // 3. 输出结果
    if (ans == -1) {
        cout << "No Solution!" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}