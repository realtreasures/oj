#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> left(n,1);
    vector<int> right(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                left[i]=max(left[i],left[j]+1);
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[j]<arr[i]){
                right[i]=max(right[i],right[j]+1);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,left[i]+right[i]-1);
    }
    cout<<n-ans<<endl;
    return 0;
}