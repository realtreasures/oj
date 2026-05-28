#include <bits/stdc++.h>
using namespace std;

int v, n;
vector<int> item;
// 二维记忆化数组：dp[i][r] = 第i个物品，剩余r容量时的最小剩余空间
vector<vector<int>> dp;

// 递归函数：返回最小剩余空间
int f(int i, int remain) {
    // 边界：无物品/无容量，返回剩余空间
    if (i >= n || remain == 0) return remain;
    // 已经计算过，直接返回
    if (dp[i][remain] != -1) return dp[i][remain];
    
    if (item[i] <= remain) {
        // 选 or 不选，取剩余空间最小的
        dp[i][remain] = min(f(i+1, remain - item[i]), f(i+1, remain));
    } else {
        // 装不下，只能不选
        dp[i][remain] = f(i+1, remain);
    }
    return dp[i][remain];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ✅ 修正输入格式！！！
    cin >> v;    // 第一行：容量
    cin >> n;    // 第二行：物品数
    
    item.resize(n);
    // ✅ 修正为二维dp
    dp.resize(n, vector<int>(v + 1, -1));
    
    for (int i = 0; i < n; i++) {
        cin >> item[i];
    }

    cout << f(0, v) << endl;

    return 0;
}