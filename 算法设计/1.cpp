#include<bits/stdc++.h>
using namespace std;

// 记忆化数组，用来存储已经计算过的子问题的结果
vector<int> dp;

// 递归函数，带有记忆化
int f(vector<int>& arr, int i, int n) {
    // 递归的终止条件：如果 i 已经超出了数组的范围，返回 0
    if (i >= n) {
        return 0;
    }

    // 如果这个子问题已经计算过，直接返回结果
    if (dp[i] != -1) {
        return dp[i];
    }

    // 选择当前元素 arr[i]，并跳过下一个元素
    int take = arr[i] + f(arr, i + 2, n);

    // 不选择当前元素，直接跳到下一个元素
    int skip = f(arr, i + 1, n);

    // 选择最大值：要么选择当前元素，要么跳过当前元素
    dp[i] = max(take, skip);
    return dp[i];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    // 输入数组
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 初始化记忆化数组，-1表示尚未计算
    dp.assign(n, -1);

    // 从索引0开始调用递归函数
    cout << f(arr, 0, n) << endl;
    return 0;
}

