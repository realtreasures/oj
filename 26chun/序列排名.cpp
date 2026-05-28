
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);

    for(auto &c:a){
        cin>>c;
        
    }
    vector<int> b=a;
    sort(b.begin(),b.end());

    map<int,int> mp;

    int idx=1;
    mp[b[0]]=1;
    for(int i=1;i<n;i++){
        if(b[i]!=b[i-1]){
            idx=i+1;
            mp[b[i]]=idx;
        }
        else{
            mp[b[i]]=idx;
        }
    }
    for(auto c:a){
        cout<<mp[c]<<' ';
    }
    return 0;
}