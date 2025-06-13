#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isInterleave(const string &s1, const string &s2, const string &s3) {
    int m = s1.length(), n = s2.length();

    // 如果 s3 长度不等于 s1 和 s2 的长度之和，直接返回 false
    if (m + n != s3.length()) return false;

    // dp[i][j] 表示 s1 的前 i 个字符和 s2 的前 j 个字符是否可以交错组成 s3 的前 i+j 个字符
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    // 初始化第一列（s1与空字符串交错组成s3的情况）
    for (int i = 1; i <= m; ++i) {
        dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
    }

    // 初始化第一行（s2与空字符串交错组成s3的情况）
    for (int j = 1; j <= n; ++j) {
        dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
    }

    // 填充整个 dp 表格
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // 检查 s1[i-1] 是否可以与 s3[i+j-1] 匹配
            if (dp[i-1][j] && s1[i-1] == s3[i+j-1]) {
                dp[i][j] = true;
            }
            // 检查 s2[j-1] 是否可以与 s3[i+j-1] 匹配
            if (dp[i][j-1] && s2[j-1] == s3[i+j-1]) {
                dp[i][j] = true;
            }
        }
    }

    // 最终结果就是 dp[m][n]
    return dp[m][n];
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        
        if (isInterleave(s1, s2, s3)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
