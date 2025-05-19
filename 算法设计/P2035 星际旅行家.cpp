#include<bits/stdc++.h>

using namespace std;

//并查集
//初始化
void init(vector<int> &L,int n){
    for(int i=1;i<=n;i++){
        L[i]=i;
    }
}

//查找
int find(vector<int> &L,int x){
    if(L[x]!=x){
        L[x]=find(L,L[x]);
    }
    return L[x];
}

//合并
void unite(vector<int> &L,int x,int y){
    int root1=find(L,x);
    int root2=find(L,y);
    if(root1!=root2){
        L[root2]=root1;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> L(n+1);
    init(L,n);
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        unite(L,u,v);
    }
    int ans=0;
    int root1=find(L,1);
    for(int i=2;i<=n;i++){
        if(find(L,i)!=root1){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}