#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//设计算法
float f(vector<float> arr,int n){
    float sum=0;
    for(int i=0;i<n-1;i++){
        sum+=arr[i];
    }
    if(sum>=arr[n-1]){
        return (sum+arr[n-1])/2.0;
    }
    else{
        return sum;
    }
}
int main(){
    //有几个电池
    int n;
    cin>>n;
    vector<float> arr(n);
    if(n==2){
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(arr[0]>=arr[1]){
            printf("%.1f\n",arr[1]);
        }
        else{
            printf("%.1f\n",arr[0]);
        }
    }
    else{
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        printf("%.1f\n",f(arr,n));
    }
    
    return 0;
}