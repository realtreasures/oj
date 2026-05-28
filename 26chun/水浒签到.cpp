

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod=998244353;
int main(){
    ll n;
    cin>>n;
    ll s=1;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        s=(s%mod*x%mod)%mod;
    }
    cout<<s%mod<<endl;
}