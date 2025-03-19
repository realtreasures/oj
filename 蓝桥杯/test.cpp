#include<iostream>
#include<cmath>

using namespace std;

// 判断 x 是否可以表示为 y^2 - z^2
bool Is_same(int a, int b){
    return a % 2 == b % 2;
}

int main() {
    int l, r; // 左右边界
    int count = 0;
    cin >> l >> r;

    // 遍历区间 [l, r] 内的每个数 i
    for (int i = l; i <= r; i++) {
        // 找到 i 的所有因子对
        for (int j = 1; j * j <= i; j++) {  // j 是 i 的一个因子
            if (i % j == 0) {
                // 因子对 j 和 i/j
                int j_match = i / j;
                
                // 检查因子是否同奇同偶
                if (Is_same(j, j_match)) {
                    count++;
                    break;  // 找到一个有效的 (j, j_match) 后跳出
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}
