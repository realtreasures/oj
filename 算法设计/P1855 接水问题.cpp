#include<bits/stdc++.h>

using namespace std;

void f(vector<int> &arr,int a,int m){
    int min_index=0;
    for(int i=1;i<m;i++){
        if(arr[min_index]>arr[i]){
            min_index=i;
        }
    }
    arr[min_index]+=a;
}
int main(){
    int n,m;
    int ans;
    cin>>n>>m;
    vector<int>arr(n+1);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> water(m);
    if(n<=m){
        ans=*max_element(arr.begin(), arr.end());
    }
    else{
        for(int i=0;i<n;i++){
            f(water,arr[i],m);
        }
        ans=*max_element(water.begin(), water.end());
    }
    cout<<ans<<endl;
    return 0;

}