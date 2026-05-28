
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定
    int n;
    cin>>n;
    ll s=0;
    vector<ll> a(n);
    for(auto &c:a){
        cin>>c;
    }
    

    for(int i=0;i<n;i++){
        ll min_x=a[i];
        for(int j=i;j<n;j++){
            s+=min(min_x,a[j]);
        }
    }
    cout<<s<<endl;
    return 0;
}