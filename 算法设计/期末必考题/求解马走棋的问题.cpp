#include<iostream>
#include<vector>
using namespace std;

int f(int i,int j,vector<vector<int>> &dp){
    if(i<=1||j<=1){
        return 0;
    }
    //只要能回到这个状态就说明有路线
    if((i==3&&j==2)||(i==2&&j==3)){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //dp核心
    dp[i][j]=f(i-1,j-2,dp)+f(i-2,j-1,dp);
    return dp[i][j];
}   

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    cout<<f(m,n,dp)<<endl;
    return 0;
}