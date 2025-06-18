#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<double> arr(n);
    for(int i=0;i<n;i++){

        cin>>arr[i];
    }
    double maxf=1;
    double maxz=1;
    double ans=0;
    for(auto it:arr){
        if(it<0){
            swap(maxz,maxf);
        }
        maxz=max(it,maxz*it);
        maxf=min(it,maxf*it);
        ans=max(ans,maxz);
    }
    cout<<(int)ans<<endl;
    return 0;
}