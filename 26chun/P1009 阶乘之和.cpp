#include<bits/stdc++.h>

using namespace std;

int f(int x){
    if(x==1){
        return 1;
    }
    return x*f(x-1);
}
int main(){
    int n;
    cin>>n;
    int ans[51]={0};
    ans[1]=1;
    for(int i=2;i<=50;i++){
        ans[i]=ans[i-1]+f(i);
    }
    cout<<ans[n]<<endl;
    return 0;
}