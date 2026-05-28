#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr);            // 解除 cin 和 cout 的绑定

    int n;
    cin >> n;

    vector<int> a(n);
    int sum = 0;

    // 读入每一堆纸牌数量，并计算总和
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    // 计算平均值
    int avg = sum / n;

    int ans = 0; // 记录最少移动次数

    // 从左到右处理前 n - 1 堆
    for (int i = 0; i < n - 1; i++) {
        // 如果当前堆不等于平均值，就必须和右边相邻堆发生一次移动
        if (a[i] != avg) {
            // 把当前堆多出来或少掉的部分转移给右边
            a[i + 1] += a[i] - avg;

            // 当前堆调整为平均值，移动次数加一
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}