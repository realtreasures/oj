#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    vector<int> card(5,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        card[x]++;
    }
    int cnt1=card[1];
    int cnt2=card[2];
    int cnt3=card[3];
    int cnt4=card[4];
    
    //定义动态规划数组，表示进行c1张1，c2张2，c3张3和c4张4，的最大值
    vector<vector<vector<vector<int>>>> dp(cnt1+1,vector<vector<vector<int>>> (cnt2+1,vector<vector<int>> (cnt3+1,vector<int> (cnt4+1,0))));

    //遍历
    dp[0][0][0][0]=a[1];
    for(int c1=0;c1<=cnt1;c1++){
        for(int c2=0;c2<=cnt2;c2++){
            for(int c3=0;c3<=cnt3;c3++){
                for(int c4=0;c4<=cnt4;c4++){
                    //初始状态
                    if(c1==0&&c2==0&&c3==0&&c4==0){
                        continue;
                    }
                    int max_current=0;
                    if(c1>0){
                        max_current=max(max_current,dp[c1-1][c2][c3][c4]);
                    }
                    if(c2>0){
                        max_current=max(max_current,dp[c1][c2-1][c3][c4]);
                    }
                    if(c3>0){
                        max_current=max(max_current,dp[c1][c2][c3-1][c4]);
                    }
                    if(c4>0){
                        max_current=max(max_current,dp[c1][c2][c3][c4-1]);
                    }
                    
                    //更新当前得分
                    dp[c1][c2][c3][c4]=max_current+a[c1+c2*2+c3*3+c4*4+1];
                }
            }
        }
    }
    cout<<dp[cnt1][cnt2][cnt3][cnt4]<<endl;
    return 0;
}