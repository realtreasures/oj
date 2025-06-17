#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
        ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    int qb=0;
    cin>>n>>m;
    vector<int> num(n);
    vector<int> val(m);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
        qb+=val[i]*num[i];
    }
    vector<int> dp(100000,1);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=qb;j>=0;j--){
            for(int p=0;p<=num[i]&&p*val[i]<=j;p++){
                dp[j]=max(dp[j],dp[j-p*val[i]]*p);
            }
        }
    }
    ll ans=0;
    while(ans<=qb&&dp[ans]<m){
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}