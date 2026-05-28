
#include<bits/stdc++.h>

using namespace std;
int main(){

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(a[j]<a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}