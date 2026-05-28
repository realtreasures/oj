

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int i=0;i<m;i++){
        int l,r,x;
        cin>>l>>r>>x;
        for(int j=l-1;j<=r-1;j++){
            num[j]=x;
        }
    }
    for(auto c:num){
        cout<<c<<' ';
    }
    cout<<endl;
    return 0;
}