#include<bits/stdc++.h>

using namespace std;
int Map[1001][1001];
int dp[1001][1001];
int f(int M[1001][1001],int i,int j){
 // 如果已经计算过，直接返回
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int up = -1, left = -1;
    
    // 如果上方有效
    if (i - 1 >= 0) {
        up = f(M, i - 1, j);
    }
    
    // 如果左方有效
    if (j - 1 >= 0) {
        left = f(M, i, j - 1);
    }

    // 选择最大的路径
    dp[i][j] = max(up, left) + M[i][j];
    
    return dp[i][j];
	
}
int main(){
	memset(dp, -1, sizeof(dp));
	dp[0][0]=0;
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>Map[i][j];
		}
	}
	cout<<f(Map,m-1,n-1);
	
}
