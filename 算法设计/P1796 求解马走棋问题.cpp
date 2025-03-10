#include <iostream>
#include <vector>
using namespace std;

int f(int m, int n, vector<vector<int>>& dp) {
    if (m == 3 && n == 2 || m == 2 && n == 3) {
        return 1;
    }
    if (m <= 0 || n <= 0) {
        return 0;  // 添加一个边界条件，避免递归越界
    }
    if (dp[m][n] != -1) {  // 如果已经计算过，直接返回结果
        return dp[m][n];
    }
    // 递归计算并存储结果
    dp[m][n] = f(m - 2, n - 1, dp) + f(m - 1, n - 2, dp);
    return dp[m][n];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));  // 初始化二维数组
    cout << f(m, n, dp) << endl;
    return 0;
}



/*
#include<iostream>
using namespace std;

int f(int m,int n){
    if((m==3&&n==2)||(m==2&&n==3)){
        return 1;
    }
    else{
        return f(m-2,n-1)+f(m-1,n-2);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<f(m,n);
}
*/
