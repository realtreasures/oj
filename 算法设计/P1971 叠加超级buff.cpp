#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<double> pre_log_fact; // pre_log_fact[k] = log10(1!) + log10(2!) + ... + log10(k!)

// 预处理阶乘的对数前缀和
void precompute(int max_k) {
    pre_log_fact.resize(max_k + 1, 0.0);
    double sum = 0.0;
    for (int i = 1; i <= max_k; ++i) {
        sum += log10(i);
        pre_log_fact[i] = sum;
    }
}

// 使用斯特林公式近似计算log10(k!)
double stirling_approx(int k) {
    if (k == 0) return 0.0;
    double log_e = log10(exp(1.0));
    return k * log10(k) - k * log_e + 0.5 * log10(2 * M_PI * k);
}

// 获取log10(k!)的值
double get_log_fact(int k) {
    if (k <= 1e6) return pre_log_fact[k];
    else return stirling_approx(k);
}

// 计算满足条件的最小y
int compute_y(int X, int Di) {
    if (X <= 1) return 0; // X>1根据题目输入约束
    double logX = log10(X);
    double target = Di;

    // 初始伤害的位数是否已足够
    if (logX >= target) return 0;

    // 倍增法确定上界
    int high = 1;
    while (true) {
        int k = high / 2;
        double sum_even = k * log10(2) + get_log_fact(k);
        double total = (high + 1) * logX + sum_even;
        if (total >= target) break;
        high *= 2;
        if (high > 1e7) { high = 1e7; break; } // 防止溢出
    }

    // 二分查找
    int low = 0, ans = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        int k = mid / 2;
        double sum_even = k * log10(2) + get_log_fact(k);
        double total = (mid + 1) * logX + sum_even;
        if (total >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    precompute(1e6); // 预处理前1e6的阶乘对数

    int X, N;
    cin >> X >> N;
    vector<int> D(N);
    for (int i = 0; i < N; ++i) cin >> D[i];

    for (int di : D) {
        cout << compute_y(X, di) << endl;
    }

    return 0;
}