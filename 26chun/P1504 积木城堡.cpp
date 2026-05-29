
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定

    int n;
    cin>>n;
    vector<int> cnt(10001,0);
    
    for(int i=0;i<n;i++){
        int x;
        vector<bool> dp(10001,false);
        dp[0]=true;
        int sum=0;
        while (cin >> x && x != -1) {
            sum += x; // 累加当前城堡总高度

            for (int j = sum; j >= x; j--) {
                dp[j] = dp[j] || dp[j - x]; // 01背包，每块积木只能用一次
            }
        }

        for(int j=sum;j>=0;j--){
            if(dp[j]){
                cnt[j]++;
            }
        }
    }

    for(int i=10000;i>=0;i--){
        if(cnt[i]==n){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0; 

    

    return 0;
}