#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
int main(){
    int n,m;//菜品数，客人数
    
    cin>>n>>m;
    vector<ll> a(n);//菜品热量
    vector<ll> b(m); //客人热量
    vector<ll> ans(m,0);//存储客人的菜单

    //输入
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<m;j++){
        cin>>b[j];
    }

    //对菜品热量排序
    sort(a.begin(),a.end());

    //使用upper_bound来查找
    for(int i=0;i<m;i++){
        auto it=upper_bound(a.begin(),a.end(),b[i]);
        cout<<it-a.begin()<<endl;
    }
    return 0;
}