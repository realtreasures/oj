#include <bits/stdc++.h>
using namespace std;


const int mod=1e6+7;



int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定

    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    vector<vector<int>> dp(103,vector<int>(103,0));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=1;k<=min(a[i],j);k++){
                //k=0表示跳过当前这种花
                dp[i][j]=(dp[i][j]+dp[i-1][j-k])%mod;
            }
        }
    }
    cout<<dp[n][m]<<endl;

    return 0;
}
