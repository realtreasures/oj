
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int max_n=1;
    int pre_max=0;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            pre_max=max(max_n,pre_max);
            max_n=1;
        }
        else{
            max_n++;
        }
    }
    pre_max=max(max_n,pre_max);
    int num=1;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            if(num==pre_max){
                cout<<a[i-1]<<endl;
            }
            num=1;
        }
        else{
            num++;
        }
    }
    if(num==pre_max){
        cout<<a[n-1]<<endl;
    }
    return 0;


}