
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定

    int n,s;
    cin>>n>>s;
    vector<ll> c(n+1);
    vector<ll> y(n+1);
    vector<ll> dp[n+1];
    for(int i=0;i<n;i++){
        cin>>c[i]>>y[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(c[i]+(j-i)*s<c[j]){
                c[j]=c[i]+(j-i)*s;
            }
        }
    }

    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=c[i]*y[i];
    }

    cout<<sum<<endl;


    return 0;
}