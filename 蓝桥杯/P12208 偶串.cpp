#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int a[30]={0};
    int len = s.length();
    for(int i=0;i<len;i++){
        a[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(a[i]%2!=0){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}