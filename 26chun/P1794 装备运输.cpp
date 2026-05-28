
// //超时了
// #include <bits/stdc++.h>
// using namespace std;

// struct node{
//     int t;
//     int v;
//     int w;
// };
// int n;
// vector<vector<vector<int>>> dp;

// int f(vector<node> a,int i,int v,int g){
//     if(i==n){
//         return 0;
//     }
//     if(dp[i][v][g]!=-1){
//         return dp[i][v][g];
//     }
//     int skip=f(a,i+1,v,g);
//     if(v>=a[i].v&&g>=a[i].w){
//         int take=f(a,i+1,v-a[i].v,g-a[i].w)+a[i].t;
//         dp[i][v][g]=max(take,skip);
//         return dp[i][v][g];
//     }
//     else{
//         dp[i][v][g]=skip;
//         return dp[i][v][g];
//     }
// }

// int main() {
//     ios::sync_with_stdio(false); // 关闭同步，加快输入输出
//     cin.tie(nullptr); // 解除 cin 和 cout 的绑定

//     int v,g;

//     cin>>v>>g;
//     cin>>n;
//     vector<node> a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i].t>>a[i].v>>a[i].w;
//     }
//     dp.resize(n+1,vector<vector<int>>(v+1,vector<int>(g+1,-1)));

//     cout<<f(a,0,v,g)<<endl;
    
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
struct node{
    int t;
    int v;
    int w;
};

vector<node> a;
vector<vector<int>> dp;


int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定

    int v,g;
    cin>>v>>g;
    int n;
    cin>>n;
    a.resize(n);
    dp.resize(v+2,vector<int>(g+2,0));
    for(int i=0;i<n;i++){
        cin>>a[i].t>>a[i].v>>a[i].w;
    }
    for(int k=0;k<n;k++){
        for(int i=v;i>=0;i--){
            for(int j=g;j>=0;j--){
                int take=0;
                if(i>=a[k].v&&j>=a[k].w){
                    take=dp[i-a[k].v][j-a[k].w]+a[k].t;
                }
                dp[i][j]=max(dp[i][j],take);
            }
        }
    }
    cout<<dp[v][g]<<endl;


    return 0;
}