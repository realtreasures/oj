#include <iostream>
#include<string>
#include<vector>
using namespace std;

int Isrestring(string s,int k){
    if(s.size()%k!=0){
        return -1;
    }
    int ans=0;
    int idex=0;
    vector<vector<char>> block;
    for(char c:s){
        block[idex%k].push_back(c);
        idex++;
    }
    for(int j=0;j<s.size()/k;j++){
        for(int i=0;i<k;i++){
            

        }
    }
}
int main(){
    int k;
    string s;
    cin>>k;
    cin>>s;
    
}