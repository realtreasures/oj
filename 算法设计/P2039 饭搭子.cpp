#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, W; // n为人数，W为每桌最大承重
    cin >> n >> W;
    vector<int> f(n); // 存储每个人的体重
    
    for (int i = 0; i < n; ++i) {
        cin >> f[i]; // 输入每个人的体重
    }
    
    sort(f.begin(), f.end()); // 体重从小到大排序

    int left = 0, right = n - 1; // 双指针，left指向最轻，right指向最重
    int tables = 0; // 桌子数量

    while (left <= right) { // 还有人没分配
        if (f[left] + f[right] <= W) { // 如果最轻和最重可以同桌
            left++; // 最轻的已分配
            right--; // 最重的已分配
        } else {
            right--; // 只能最重的单独一桌
        }
        tables++; // 增加桌子数
    }

    cout << tables << endl; // 输出最少桌数
    return 0;
}
