#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int sp[10000];
int val[10000];
int dp[1000][1000];
int f( int i, int cur,int n,int v){
    if(i>=n||cur>v){
        return 0;
    }
    if(dp[i][cur]!=-1){
        return dp[i][cur];
    }
    else{
        int take=0;
        if(cur>=sp[i]) 
        take=val[i]+f(i+1,cur-sp[i],n,v);
        int skip=f(i+1,cur,n,v);
        dp[i][cur]=max(take,skip);
        return dp[i][cur];
    }
}
int main(){
    int v,n;
    cin>>v>>n;
    
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>sp[i]>>val[i];
    }
    cout<<f(0,v,n,v)<<endl;
    return 0;

}