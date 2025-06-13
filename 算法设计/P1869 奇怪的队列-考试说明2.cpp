#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n;
    cin>>n;
    vector<int> h(n);
    for(auto &it:h){
        cin>>it;
    }
    int pre=0;
    int count=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(h[i]>h[i+1]){
            if(pre==0||pre==-1){
                ans+=(count);
                pre=1;
                count=0;
            }
            else{
                pre=1;
                count++;
            }
        }
        else if(h[i]==h[i-1]){
            ans++;
        }
        else{
            if(pre==0||pre==1){
                ans+=(count);
                pre=-1;
                count=0;
            }
            else{
                pre=-1;
                count++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
