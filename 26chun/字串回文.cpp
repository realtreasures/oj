
#include <bits/stdc++.h>
using namespace std;

bool Is_hui(string s){
    string c=s;
    reverse(s.begin(),s.end());
    if(c==s){
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定

    string s;
    cin>>s;
    int ans=0;
    for(int l=0;l<s.size();l++){
        for(int r=l+1;r<s.size()+1;r++){
            string c=s.substr(l,r-l);

            if(Is_hui(c)){
                ans++;
            }
        }

    }
    cout<<ans<<endl;
    return 0;
}