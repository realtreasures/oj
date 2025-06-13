#include <iostream>
#include <algorithm>  // 引入 max 函数
using namespace std;

int main() {
    int n;
    cin >> n;  // 输入数组长度
    int a[n];
    
    // 输入数组元素
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 初始化 current_sum 和 max_sum
    int current_sum = a[0];
    int max_sum = a[0];
    
    // 遍历数组从第二个元素开始
    for (int i = 1; i < n; ++i) {
        // 更新 current_sum：选择当前元素或者当前元素加上前面的和
        current_sum = max(a[i], current_sum + a[i]);
        
        // 更新最大和
        max_sum = max(max_sum, current_sum);
    }
    
    // 输出结果
    cout << max_sum << endl;
    return 0;
}
