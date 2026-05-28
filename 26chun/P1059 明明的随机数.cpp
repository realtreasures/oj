
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定

    int n;
    cin>>n;
    set<int> num;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        num.insert(x);
    }
    cout<<num.size()<<endl;
    for(auto i:num){
        cout<<i<<' ';
    }
    cout<<endl;

    return 0;
}