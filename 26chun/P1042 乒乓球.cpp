#include <bits/stdc++.h>
using namespace std;

void eleven(string s){
    int w=0;
    int l=0;
    for(auto c:s){
        if(c=='E'){
            cout<<w<<':'<<l<<endl;
            return;
        }
        else{
            if(c=='W'){
                w++;
                if(w>=11&&w-l>=2){
                    cout<<w<<':'<<l<<endl;
                    l=0;
                    w=0;
                }
            }
            else if(c=='L'){
                l++;
                if(l>=11&&l-w>=2){
                    cout<<w<<':'<<l<<endl;
                    l=0;
                    w=0;
                }
            }
        }
    }
}

void tenty_noe(string s){
    int w=0;
    int l=0;
    for(auto c:s){
        if(c=='E'){
            cout<<w<<':'<<l<<endl;
            return;
        }
        else{
            if(c=='W'){
                w++;
                if(w>=21&&w-l>=2){
                    cout<<w<<':'<<l<<endl;
                    l=0;
                    w=0;
                }
            }
            else if(c=='L'){
                l++;
                if(l>=21&&l-w>=2){
                    cout<<w<<':'<<l<<endl;
                    l=0;
                    w=0;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定
    string s="";
    while(true){
        char c;
        cin>>c;
        s+=c;
        if(c=='E'){
            break;
        }

    }
    eleven(s);
    cout<<endl;
    tenty_noe(s);

    return 0;
}