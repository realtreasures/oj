#include<iostream>
#include<algorithm>
#include<vector>
#define INF 1e+7
using namespace std;

int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<vector<int>> dist(n+1,vector<int>(n+1,INF));

    for(int i=1;i<=n;i++){
        dist[i][i]=0;
    }

    for(int i=1;i<=m;i++){
        int u,v,d;
        cin>>u>>v>>d;
        dist[u][v]=d;
        dist[v][u]=d;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]<INF&&dist[k][j]<INF){
                    dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
                }
            }
        }
    }
    int lx=dist[x][n];
    int zs=dist[y][n];
    if(lx<=zs){
        cout<<"YES "<<lx<<endl;
    }
    else{
        cout<<"NO "<<zs<<endl;
    }
    return 0;
}