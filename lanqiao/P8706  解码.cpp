#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<char> a;
    char c;
    while(cin.get(c)){
        if(c=='\n')
        break;
        if(c>='1'&&c<='9'){
            int num=c-'0';
            c=a.top();
            a.pop();
            for(int i=0;i<num;i++){
                a.push(c);
            }
        }
        else{
            a.push(c);
        }
    }
    stack<char> ans;
    while(!a.empty()){
        ans.push(a.top());
        a.pop();
    }
    while(!ans.empty()){
        cout<<ans.top();
        ans.pop();
    }
    return 0;
}