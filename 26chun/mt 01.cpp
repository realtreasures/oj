
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 5005;

// 预处理组合数 C[i][j]：从i个里选j个的方案数
long long C[MAXN][MAXN];

// 初始化组合数
void init() {
    C[0][0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init(); // 预处理组合数
    
    int n;
    string s;
    cin >> n >> s;
    
    vector<int> pos; // 存储原串中1的位置
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            pos.push_back(i);
        }
    }
    int c = pos.size(); // 1的总数
    long long ans = 0;
    
    // 遍历每个1，计算独立贡献
    for (int k = 0; k < c; ++k) {
        int p = pos[k];       // 第k个1的原位置
        int need_l = k;       // 左边需要选的1的数量
        int need_r = c - k - 1; // 右边需要选的1的数量
        
        // 遍历所有可能的目标位置x
        for (int x = 0; x < n; ++x) {
            // 左边方案数：x个位置选need_l个
            long long cl = C[x][need_l];
            // 右边方案数：(n-1-x)个位置选need_r个
            long long cr = C[n-1 - x][need_r];
            // 总方案数
            long long cnt = cl * cr % MOD;
            // 贡献：|p-x| * 方案数
            long long add = 1LL * abs(p - x) * cnt % MOD;
            ans = (ans + add) % MOD;
        }
    }
    
    cout << ans % MOD << endl;
    return 0;
}