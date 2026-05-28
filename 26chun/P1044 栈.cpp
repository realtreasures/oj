#include <bits/stdc++.h>
using namespace std;
int n;

vector<vector<int>> a;

long long dfs(int push,int pop){
    if(pop==n)
        return 1;
    else if(a[push][pop]!=-1)
        return a[push][pop];
    else{
        long long res=0;
        if(push<n){
            res+=dfs(push+1,pop);
        }
        if(push>pop){
            res+=dfs(push,pop+1);
        }
        a[push][pop]=res;
        return a[push][pop];
    }
    
}

int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定

    cin>>n;
    a.resize(n+1,vector<int>(n+1,-1));
    cout<<dfs(0,0)<<endl;
    return 0;
}