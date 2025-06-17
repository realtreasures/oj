#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main() {
    int v, n;
    cin >> v >> n;
    
    int sp[10000]; // 物品体积
    int val[10000]; // 物品价值
    int dp[10001] = {0}; // dp[j]: 容量j时的最大价值
    
    // 输入物品数据
    for(int i = 0; i < n; i++) {
        cin >> sp[i] >> val[i];
    }
    
    // 01背包动态规划
    for(int i = 0; i < n; i++) {
        // 倒序枚举容量
        for(int j = v; j >= sp[i]; j--) {
            dp[j] = max(dp[j], dp[j - sp[i]] + val[i]);
        }
    }
    
    cout << dp[v] << endl;
    return 0;
}