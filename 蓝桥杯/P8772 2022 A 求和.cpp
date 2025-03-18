
//暴力超时
/*
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    long long int s=0;
    cin>>n;
    vector <int>a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            s+=a[i]*a[j];
        }
    }
    cout<<s<<endl;
    return 0;
}
*/

//此题注意范围，要使用long long
#include<bits/stdc++.h>

using namespace std;

//平方差公式
long long int square(vector<int> num){
    long long int sum=0,square_s=0;
    for(int &a:num){
        sum+=a;
        square_s+=a*a;
    }
    return (sum*sum-square_s)*0.5;
}
int main(){
    int n;
    cin>>n;
    vector<int> num(n);

    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    cout<<square(num)<<endl;
    return 0;
}