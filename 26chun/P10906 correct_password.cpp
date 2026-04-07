#include<iostream>
#include<string>
#include<cctype>
#include<vector>
using namespace std;

bool Iscorrect(string s){
    bool flag_number=false;
    bool flag_sign=false;
    for(char c:s){
        if(c>='0'&&c<='9'){
            flag_number=true;
        }
        if(!isalnum(c)){
            flag_sign=true;
        }
    }
    if(flag_number&&flag_sign){
        return true;
    }
    return false;
}

int main(){
    string s="kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";
    vector<string> v;
    for(int i=0;i<=s.size()-8;i++){
        if(i+8<=s.size()){
            v.push_back(s.substr(i,8));
        }
        if(i+9<=s.size()){
            v.push_back(s.substr(i,9));
        }
        if(i+10<=s.size()){
            v.push_back(s.substr(i,10));
        }
        if(i+11<=s.size()){
            v.push_back(s.substr(i,11));
        }
        if(i+12<=s.size()){
            v.push_back(s.substr(i,12));
        }
        if(i+13<=s.size()){
            v.push_back(s.substr(i,13));
        }       
        if(i+14<=s.size()){
            v.push_back(s.substr(i,14));
        }   
        if(i+15<=s.size()){
            v.push_back(s.substr(i,15));
        }
        if(i+16<=s.size()){
            v.push_back(s.substr(i,16));
        }
    }
    int ans=0;
    for(string s:v){
        if(Iscorrect(s)){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}