
//dp[j][k]表示花费j元，k人品的最优效果；
// 人数优先，然后是时间
#include <bits/stdc++.h>
using namespace std;

struct mm{
    int rmb;
    int rp;
    int time;
};

struct node{
    int cnt;
    int tim;
};

int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定

    int n;
    cin>>n;

    vector<mm> meizi(n);
    for(auto &c:meizi){
        cin>>c.rmb>>c.rp>>c.time;
    }

    int m,r;
    cin>>m>>r;
    vector<vector<node>> dp(m+1,vector<node>(r+1,{0,0}));

    for(int i=0;i<n;i++){
        for(int j=m;j>=meizi[i].rmb;j--){
            for(int k=r;k>=meizi[i].rp;k--){
                if(dp[j][k].cnt<dp[j-meizi[i].rmb][k-meizi[i].rp].cnt+1){
                    dp[j][k].tim=dp[j-meizi[i].rmb][k-meizi[i].rp].tim+meizi[i].time;
                    dp[j][k].cnt=dp[j-meizi[i].rmb][k-meizi[i].rp].cnt+1;
                }
                else if(dp[j][k].cnt==dp[j-meizi[i].rmb][k-meizi[i].rp].cnt+1){
                    dp[j][k].tim=min(dp[j][k].tim,dp[j-meizi[i].rmb][k-meizi[i].rp].tim+meizi[i].time);
                }
                
            }
        }
    }
    cout<<dp[m][r].tim<<endl;

    return 0;
}