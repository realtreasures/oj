#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<vector<int>> map(10001);
int deg[10011]={0};
int main(){
    int n,m;
    long long int ans=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        map[a].push_back(b);
        map[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    for(int i=1;i<=n;i++){
        for(int j:map[i]){
            ans+=(deg[i]-1)*(deg[j]-1);
        }
        
    }
    cout<<ans<<endl;
    return 0;
    
}