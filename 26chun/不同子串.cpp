
#include<bits/stdc++.h> 

using namespace std;

int main(){

    set<string> u;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size()+1;j++){
            string c=s.substr(i,j-i);
            u.insert(c);
        }
    }
    cout<<u.size()<<endl;
    return 0;
}