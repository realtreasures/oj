#include<bits/stdc++.h>
using namespace std;
int n,V;
int a[1005];

int f(int a[1005],int i,int n,int V){
	if(i>=n||V-a[i]<0){
		return 0;
	}
	else{
		int take=f(a,i+1,n,V-a[i])+a[i];
		return take;
	}
}
int main(){
	cin>>n>>V;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int> ans;
	for(int i=0;i<n;i++){
		ans.push_back(f(a,i,n,V)); 
	}
	cout<<*max_element(ans.begin(),ans.end())<<endl;
	return 0;
}
