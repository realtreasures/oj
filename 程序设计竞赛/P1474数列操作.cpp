#include <iostream>
#include <queue>
#include <vector>
#include <functional>  // 用于greater比较器

using namespace std;

int main() {
    int n;
    while (cin >> n) {  // 读取多组输入
        vector<long long> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];  // 读取每个数字
        }
        
        // 创建最小堆（小顶堆）
        priority_queue<long long, vector<long long>, greater<long long>> heap;
        for (auto num : nums) {
            heap.push(num);
        }
        
        // 合并操作直到只剩一个元素
        while (heap.size() > 1) {
            long long a = heap.top();
            heap.pop();
            long long b = heap.top();
            heap.pop();
            long long merged = a * b + 1;
            heap.push(merged);
        }
        
        // 输出最终结果
        cout << heap.top() << endl;
    }
    return 0;
}