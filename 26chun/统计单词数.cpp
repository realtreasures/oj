
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定

    
    string s,c;
    int count=0;
    cin>>c;

    getchar();

    getline(cin,s);
    for(auto &i:c){
        i=tolower(i);
    }
    for(auto &i:s){
        i=tolower(i);
    }
    c=' '+c;
    s=' '+s;
    s=s+' ';
    c=c+' ';
    int pos=s.find(c);

    if(pos==-1){
        cout<<-1<<endl;
    }
    else{
        for(int i=pos;i<s.size();i++){
            if(s.find(c,i)!=-1){
                count++;
            }
        }
        cout<<pos<<' '<<count<<endl;
    }
    return 0;
}