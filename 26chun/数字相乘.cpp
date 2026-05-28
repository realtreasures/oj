
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod=1000000000;

ll f(ll x){
    while(x!=0){
        int temp=x%10;
        if(temp!=0){
            return temp;
        }
        else{
            x=x/10;
        }
    }
}
int main(){
    ll n;
    cin>>n;

    ll s=1;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        s=(s*x)%mod;
        
    }

    cout<<f(s)<<endl;
    return 0;
}