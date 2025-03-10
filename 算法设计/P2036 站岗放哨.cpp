
#include<iostream>
using namespace std;

// 求组合数 C(m, n)
int f(int m, int n) {
    if (n == 0 || m == n)  // 组合数基本情况
        return 1;
    return f(m-1, n-1) + f(m-1, n);  // 递归公式：C(m, n) = C(m-1, n-1) + C(m-1, n)
}

int main() {
    int m, n;
    int a[100];
    cin >> m >> n;  // 输入 m 和 n
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    cout << f(m, n) << endl;  // 输出组合数 C(m, n)
    return 0;
}
