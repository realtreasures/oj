#include<bits/stdc++.h>

using namespace std;

const int mod=998244353;

int main(){
    int a,n;
    cin>>a>>n;
    long long ans=0;
    long long s=0;
    for(int i=0;i<n;i++){
        s=((s)%mod*10+a)%mod;
        ans=(ans+s)%mod;
    }
    cout<<ans%mod<<endl;
    return 0;
}