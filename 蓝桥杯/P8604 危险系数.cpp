#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> map[10001];
bool visited[10001];

bool dfs(int x,int y,int ban){
    if(x==y){
        return true;
    }
    visited[x]=true;
    for(int next:map[x]){
        if(next==ban){
            continue;
        }
        if(!visited[next]){
            if(dfs(next,y,ban)){
                return true;
            }
        }
        
    }
    return false;
}

bool Isconnected(int x,int y,int ban){
    memset(visited,false,sizeof(visited));
    return dfs(x,y,ban);
}

int main(){
    
    int n,m;
    int ans=0;
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    int start,end;
    cin>>start>>end;
    for(int i=1;i<=n;i++){
        if(i==start||i==end){
            continue;
        }

        if(!Isconnected(start,end,i)){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}