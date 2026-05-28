

// #include <bits/stdc++.h>
// using namespace std;
struct yao{
    int time;
    int value;
};
// vector<yao> y;
// vector<vector<int>> flag;
// int t,m;

// int pick(int i,int time){
//     if(i>=m||time==0)
//         return 0;
//     if(flag[i][time]!=-1){
//         return flag[i][time];
//     }
//     else{
//         int pass=pick(i+1,time);
//         int take;
//         if(time-y[i].time<0){
//             take=0;
//         }
//         else{
//             take=pick(i+1,time-y[i].time)+y[i].value;
//         }
//             flag[i][time]=max(pass,take);
//             return flag[i][time];
//     }
    
        

// }

// int main() {
//     ios::sync_with_stdio(false); // 关闭同步，加快输入输出
//     cin.tie(nullptr); // 解除 cin 和 cout 的绑定

//     cin>>t>>m;
//     y.resize(m+1);
//     flag.resize(m+1,vector<int>(t+1,-1));
//     for(int i=0;i<m;i++){
//         cin>>y[i].time>>y[i].value;
//     }


//     cout<<pick(0,t)<<endl;
     


//     return 0;
// }

// 另解一维dp

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定

    int t,m;
    cin>>t>>m;
    vector<yao> y(m);
    vector<int> dp(t+1,0);
    for(int i=0;i<m;i++){
        cin>>y[i].time>>y[i].value;
    }
    for(auto c:y){
        for(int j=t;j>=c.time;j--){
            dp[j]=max(dp[j],dp[j-c.time]+c.value);
        }
    }
    cout<<dp[t]<<endl;

    return 0;
}