#include<iostream>
#include<vector>
using namespace std;

void f(vector<vector<int>> &arr,vector<int> &visited,int i,int n){
    if(visited[i]==0){
        return;
    }
    visited[i]=0;
    for(int j=1;j<=n;j++){
        if(j==i){
            continue;
        }
        if(arr[i][j]==0){
            f(arr,visited,j,n);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> visited(n+1,-1);
    vector<vector<int>> arr(n+1,vector<int>(n+1,-1));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        arr[u][v]=0;
        arr[v][u]=0;
    }
    f(arr,visited,1,n);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(visited[i]==-1){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}