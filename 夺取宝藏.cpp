#include<bits/stdc++.h>

using namespace std;
int Map[1001][1001];
int dp[1001][1001];
int f(int M[1001][1001],int i,int j){
 // ����Ѿ��������ֱ�ӷ���
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int up = -1, left = -1;
    
    // ����Ϸ���Ч
    if (i - 1 >= 0) {
        up = f(M, i - 1, j);
    }
    
    // �������Ч
    if (j - 1 >= 0) {
        left = f(M, i, j - 1);
    }

    // ѡ������·��
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
