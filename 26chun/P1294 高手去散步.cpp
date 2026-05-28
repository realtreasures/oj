#include<bits/stdc++.h>

using namespace std;

bool vis[100005]={false};
// 答案：最长路径
int ans = 0;
int n, m;
void dfs(vector<vector<int>>& info,int x,int len){
    ans=max(ans,len);
    vis[x]=true;
    for(int i=0;i<=n;i++){
        if(info[x][i]&&!vis[i]){
            dfs(info,i,len+info[x][i]);
            vis[i]=false;
        }
    }
}

int main(){
    cin>>n>>m;
    vector<vector<int>> info(n+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        info[x][y]=z;
        info[y][x]=z;
    }
    for(int i=1;i<=n;i++){
        memset(vis, 0, sizeof(vis)); // 清空标记
        dfs(info,i,0);
    }
    cout<<ans<<endl;
    return 0;


}