#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int longestIncreasingSubsequence(const string& s) {
    int n = s.length();
    if (n == 0) return 0;

    vector<int> dp(n, 1);  // dp[i] 表示以 s[i] 结尾的最长递增子序列的长度

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (s[j] < s[i]) {
                dp[i] = max(dp[i], dp[j] + 1);  // 如果 s[j] < s[i]，则可以更新 dp[i]
            }
        }
    }

    return *max_element(dp.begin(), dp.end());  // 返回 dp 中的最大值
}

int main() {
    int n;
    while (cin >> n) {  // 通过循环读取多个测试案例
        // 读取多组输入
        while (n--) {
            string s;
            cin >> s;  // 读取每个字符串
            cout << longestIncreasingSubsequence(s) << endl;  // 输出该字符串的 LIS 长度
        }
    }

    return 0;
}
