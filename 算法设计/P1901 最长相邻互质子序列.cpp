#include <iostream>
#include <vector>
#include <algorithm>

// 如果你的编译器不支持 C++17，可以使用以下自定义的 GCD 函数
// 欧几里得算法计算最大公约数
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

using namespace std;

int main() {
    int n;
    cin >> n;  // 输入序列的长度
    vector<int> a(n);
    
    // 输入序列
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // dp[i]表示以a[i]结尾的最长子序列长度
    vector<int> dp(n, 1);

    // 遍历每一对 (i, j)
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (gcd(a[i], a[j]) == 1) {  // 如果 a[i] 和 a[j] 互质
                dp[i] = max(dp[i], dp[j] + 1);  // 更新 dp[i]
            }
        }
    }

    // 最长子序列的长度是 dp 数组中的最大值
    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}
