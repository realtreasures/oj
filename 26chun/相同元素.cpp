
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    map<int,int> mp;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(mp.find(a[i])!=mp.end()){
            mp[a[i]]=mp[a[i]]+1;
        }
        else{
            mp[a[i]]=0;
        }
    }
    for(auto c:a){
        cout<<mp[c]<<' ';
    }
    cout<<endl;
    return 0;
}