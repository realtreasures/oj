
#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定
    int n;
    cin>>n;
    int x;
    vector<int> a(101,0);
    int cnt=0;
    for(int i=0;i<n;i++){
        
        cin>>x;
        for(int j=x+1;j<=100;j++){
            cnt=(cnt+a[j])%100;
        }
        a[x]++;
    }
    cout<<cnt<<endl;
    
    return 0;
}