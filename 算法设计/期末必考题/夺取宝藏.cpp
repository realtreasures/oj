#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int Map[1001][1001];
int dp[1001][1001];
int f(int i,int j){
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=-1;
    int left=-1;
    if(i-1>=0){
        up=f(i-1,j);
    }
    if(j-1>=0){
        left=f(i,j-1);
    }
    dp[i][j]=max(up,left)+Map[i][j];
        return dp[i][j];
}

int main(){
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>Map[i][j];
        }
    }
    cout<<f(m-1,n-1)<<endl;
    return 0;

}