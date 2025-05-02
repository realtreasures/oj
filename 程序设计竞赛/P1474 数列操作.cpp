#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int processSequence(const vector<int>& nums) {
    // 使用最大堆来解决问题
    priority_queue<int> pq(nums.begin(), nums.end());  // 最大堆

    while (pq.size() > 1) {
        // 取出堆顶的两个最大值
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        // 计算新值并插入堆中
        pq.push(a * b + 1);
    }

    return pq.top();  // 最终剩下的一个值
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cout << processSequence(nums) << endl;
    }

    return 0;
}
