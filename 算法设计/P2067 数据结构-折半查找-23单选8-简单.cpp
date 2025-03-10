#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n,ans;
    cin>>n;
    int temp=log2(n+1);
    if(log2(n+1)-temp==0)
        ans=temp;
    else
        ans=temp+1;
    cout<<ans<<endl;
}