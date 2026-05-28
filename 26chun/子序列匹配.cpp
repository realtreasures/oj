
#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string t;
        cin>>t;
        int k,j;
        for(j=0,k=0;j<s.size()&&k<t.size();j++){
            if(t[k]==s[j]){
                k++;
            }
        }
        if(k==t.size()){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}