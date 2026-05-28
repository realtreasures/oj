
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定

    
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> sum(n+1,0);
    vector<int> dp(n+1,-1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    if(sum[n]<0){
        cout<<"Impossible"<<endl;
        return 0;
    }
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(dp[j]!=-1&&sum[i]-sum[j]>=0){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }

    cout<<dp[n]<<endl;




    return 0;
}