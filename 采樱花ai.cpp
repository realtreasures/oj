#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, V;
    cin >> n >> V;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int left = 0, current_sum = 0, max_sum = 0;
    for(int right = 0; right < n; ++right) {
        current_sum += a[right];
        // 当当前和超过容量时，移动左指针缩小窗口
        while (current_sum > V && left <= right) {
            current_sum -= a[left];
            left++;
        }
        // 更新最大和
        if (current_sum > max_sum && current_sum <= V) {
            max_sum = current_sum;
        }
    }
    cout << max_sum << endl;
    return 0;
}
