#include<bits/stdc++.h>

using namespace std;

int f(vector<int>& arr,int i,int n,vector<int>& dp){
	if(i>=n){
		return 0;
	}
	if(dp[i]!=-1){
		return dp[i];
	}
	int sel=f(arr,i+2,n,dp)+arr[i];
	int skip=f(arr,i+1,n,dp);
	//int max_val=max(sel,skip);
	dp[i]=max(sel,skip);
	return dp[i];
}
int main(){
	int n;
	int ans=0;
	cin>>n;
	vector<int> arr(n+1);
	int ans1=0,ans2=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int> dp(n,-1);
	cout<<f(arr,0,n,dp)<<endl;
	return 0;
	
} 
