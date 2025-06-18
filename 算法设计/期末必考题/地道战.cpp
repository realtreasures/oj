#include<iostream>
#include<vector>
using namespace std;

int f(vector<int> &arr,int i,int n,vector<int> &dp){
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    //核心
    int take=f(arr,i+2,n,dp)+arr[i];
    int skip=f(arr,i+1,n,dp);
    dp[i]=max(take,skip);
    return dp[i];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> dp(n,-1);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<f(arr,0,n,dp)<<endl;
    return 0;
}