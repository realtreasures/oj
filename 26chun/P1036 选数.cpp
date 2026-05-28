

#include <bits/stdc++.h>
using namespace std;

vector<int> path;
vector<int> num;
int n,k;
int ans=0;

bool Is_su(int x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0)
            return false;
    }
    return true;
}


void dfs(int start){
    if(path.size()==k){

        int s=accumulate(path.begin(),path.end(),0);
        if(Is_su(s)){
            ans++;
        }
        return;
    }
    else{
        for(int i=start;i<n;i++){
            path.push_back(num[i]);
            dfs(i+1);
            path.pop_back();
        }
        
    }
}

int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定


    cin>>n>>k;
     num.resize(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }

    dfs(0);
    cout<<ans<<endl;
    return 0;
}