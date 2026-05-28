
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    map<string,int> mp;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;

        mp.insert({s,0});
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int opt;
        cin>>opt;
        if(opt==1){
            string x;
            int y;
            cin>>x>>y;
            if(mp.find(x)!=mp.end()){
                mp[x]=mp[x]+y;
            }
            
        }
        else{
            string x;
            cin>>x;
            if(mp.find(x)!=mp.end()){
                cout<<mp[x]<<endl;
            }
            else{
                cout<<-1<<endl;
            }
           
        }
    }
    return 0;
}