
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int s=a[0];
    int ans=s;

    for(int i=1;i<n;i++){
        s=max(s+a[i],a[i]);
        ans=max(ans,s);
    }
    cout<<ans<<endl;




    return 0;
}