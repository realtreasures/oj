
#include<iostream>
#include<vector>

using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> dp_ji(n+1,0);
    vector<int> dp_ou(n+1,0);
    if((arr[0]+arr[1])%2){
        dp_ji[2]=1;
    }
    else{
        dp_ou[2]=1;
    }
    for(int i=2;i<n;i++){
        if((arr[i]+arr[i-1])%2){
            dp_ji[i+1]=dp_ji[i]+1;
        }
    }
}