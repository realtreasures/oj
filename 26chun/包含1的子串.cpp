
#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定
    int n;
    cin>>n;
    string s;
    cin>>s;
    long long ans=0;
    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=i;j<n;j++){
            if(s[j]=='1'){
                flag=1;
                ans+=n-j;
                break;
            }            
        }
    }
    cout<<ans<<endl;
    return 0;

}