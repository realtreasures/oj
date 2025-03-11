
#include<iostream>
#include<unordered_map>
#include<vector>

typedef long long ll;
using namespace std;

//first为要查的数，second是下标
unordered_map<ll,int> num;

int main(){
    ll x;//数列第一项
    ll y;//数列第二项
    ll z;//一共的相数
    ll n;//要查询的次数

    cin>>x>>y>>z;
    cin>>n;

    //辅助数组
    vector<ll> a(z);

    num.insert({x,0});
    num.insert({y,1});
    a[0]=x;
    a[1]=y;
    //构造数列
    for(ll i=2;i<z;i++){
        a[i]=a[i/2]+a[i/4];
        auto it=num.find(a[i]);
        if(it==num.end())
            num.insert({a[i],i});
        else{
            continue;
        }
    }

    //n次查询
    for(ll i=0;i<n;i++){
        ll find_num;
        cin>>find_num;
        auto it=num.find(find_num);
        if(it!=num.end()){
            cout<<it->second<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }

    }
    return 0;
}