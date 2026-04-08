#include<iostream>

#include<string>

using namespace std;

string insertbeforebigger(string s,char x){
    for(int i=0;i<=s.size();i++){
        if(s[i]>=x){
            return s.substr(0,i)+x+s.substr(i);
        }
    }
    return s+x;
}

int main(){
    int n;
    int m;
    string s;
    string c;
    cin>>n>>m;
    cin>>s>>c;
    for(char x:c){
        s=insertbeforebigger(s,x);
    }
    cout<<s<<endl;
    return 0;

    
}