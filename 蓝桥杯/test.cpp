#include<iostream>
#include<set>
#include<cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 存直线
    set<pair<int, int>> lines;
    // 存交点
    set<pair<double, double>> points;

    // 读取直线的参数
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        lines.insert({a, b});
    }

    // 遍历每两条线，计算交点
    for (auto it = lines.begin(); it != lines.end(); ++it) {
        for (auto it2 = next(it); it2 != lines.end(); ++it2) {
            int k1 = it->first;
            int b1 = it->second;
            int k2 = it2->first;
            int b2 = it2->second;

            if (k1 != k2) {  // 避免平行线
                // 计算交点 (x, y)
                double x = (double)(b2 - b1) / (k1 - k2);  // 使用浮点数进行除法
                double y = k1 * x + b1;                     // 计算交点 y

                // 将交点插入 set 中，保证交点唯一
                points.insert({x, y});
            }
        }
    }

    // 计算区域数目：公式 R(N) = 1 + C(N, 2) = 1 + N * (N - 1) / 2 + 交点数
    int num_l = lines.size();
    int num_p = points.size();
    
    // 输出结果
    cout << 1 + num_l + num_p << endl;

    return 0;
}
