//差分加二分
#include <bits/stdc++.h>
using namespace std;

struct hire{
    long long nu;
    int st;
    int en;
};
vector<hire> h;
vector<int> day;
int n,m;

bool check(int x){
    long long int need=0;
    vector<long long> diff(n+2);
    for(int i=1;i<=x;i++){
        diff[h[i].st]+=h[i].nu;
        diff[h[i].en+1]-=h[i].nu;
    }
    for(int i=1;i<=n;i++){
        need+=diff[i];
        if(need>day[i]){
            return false;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定

  
    cin>>n>>m;
    day.resize(n+2);
    h.resize(m+2);
    for(int i=1;i<=n;i++){
        cin>>day[i];
    }
    for(int i=1;i<=m;i++){
        cin>>h[i].nu>>h[i].st>>h[i].en;
    }
    if(check(m)){
        cout<<0<<endl;
        return 0;
    }
    int left=1;
    int right=m;
    int ans=m;

    while(left<=right){
        int mid=(left+right)/2;
        if(check(mid)){
            left=mid+1;
        }else{
            ans=mid;
            right=mid-1;
        }
    }
    cout<<-1<<endl;
    cout<<ans<<endl;
    return 0;
}