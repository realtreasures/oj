
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定

    int l,n;
    cin>>l>>n;
    if(n==0){
        cout<<0<<" "<<0<<endl;
        return 0;
    }

    vector<int> a(n);
    

    for(int &c:a){
        cin>>c;
    }

    int min_ans=INT_MIN;
    int max_ans=INT_MIN;
    for(int &c:a){
        min_ans=max(min_ans,min(c,l-c+1));
        max_ans=max(max_ans,max(c,l-c+1));
    }

    cout<<min_ans<<" "<<max_ans<<endl;
    return 0;
}