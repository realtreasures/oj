#include<iostream>
#include<cmath>
#include<map>
using namespace std;

map<int, int> num;

// 判断位数的函数
void f(int x) {
    double logX = log10(x); // 计算 log10(x)
    double dir = logX; // 初始化 dir 为 log10(x)
    num[1] = 0; // 初始时，施放 0 次的伤害位数为 1 位

    // 从施放 1 次到 100001 次
    for (int count = 1; count < 100002; count++) {
        // 每次施放增加 log10(x)
        dir += logX;
        
        // 如果施放次数为偶数，则额外增加 log10(count)
        if (count % 2 == 0) {
            dir += log10(count);
        }
        
        // 计算当前施放次数后的伤害位数，取整后存入 map
        num[floor(dir) + 1] = count;
    }
}

int main() {
    int x, y;
    cin >> x >> y;  // 输入初始伤害值 x 和怪物数量 y

    // 预处理伤害位数到施放次数的映射
    f(x);

    // 处理每个怪物的血量位数
    for (int i = 0; i < y; i++) {
        int di;
        cin >> di;  // 输入怪物的血量位数 di
        auto it = num.lower_bound(di);  // 查找大于或等于 di 的最小值

        // 输出找到的施放次数
        cout << it->second << endl;
    }

    return 0;
}
