
#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
        
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int opt,x,k;
        cin>>opt>>x>>k;
        x=x-1;
        if(opt==1){
            vector<int> temp(a[x].begin()+k,a[x].end());
            for(int j=0;j<k;j++){
                temp.push_back(a[x][j]);
            }
            a[x]=temp;
        }
        else{
            vector<int> temp(a[x].begin()+(m-k),a[x].end());
            for(int j=0;j<(m-k);j++){
                temp.push_back(a[x][j]);
            }
            a[x]=temp;
        }
        
    }

    for(int k=0;k<n;k++){
            for(int j=0;j<m;j++){
                cout<<a[k][j]<<' ';
            }
            cout<<endl;
        }
    return 0;
}