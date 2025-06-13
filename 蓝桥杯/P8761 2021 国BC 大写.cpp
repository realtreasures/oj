#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    string s;
    cin>>s;
    for(char &it:s){
        if(it>='a'&&it<='z'){
            it=it-'a'+'A';
        }
    }
    cout<<s<<endl;
    return 0;
}