#include<iostream>
//#include<cmath>
using namespace std;
int main(){
    int n;
    int a[100001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int max_sum=a[0];
    int current_sum=a[0];
    for(int i=1;i<n;i++){
        current_sum=max(current_sum+a[i],a[i]);
        max_sum=max(max_sum,current_sum);
    }
    cout<<max_sum<<endl;
    return 0;
}