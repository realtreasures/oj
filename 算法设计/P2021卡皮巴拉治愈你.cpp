#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k,m;
    cin>>n>>k>>m;
    vector<int> a(n);
    vector<int> pressure(n,0);
    for(int i=0;i<n;i++){
        cin>>a[n];
    }
    copy(a.begin(),a.end(),pressure.begin());
    //计算卡皮巴拉放在第i个人的头上的影响
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            if(i+j<n){
                pressure[i]+=a[i+j];
            }
            if(i-j>=0){
                pressure[i]+=a[i-j];
            }
        }
    }
    //dp[i][j]动态规划记录在前i个人放j个卡皮巴拉的最大影响
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    //初始化
    for(int i=1;i<=n;i++){
        dp[i][]
    }
    
}