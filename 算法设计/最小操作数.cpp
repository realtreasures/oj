#include<bits/stdc++.h>

using namespace std;
/*
题目：
给定长度为n的数组A，每次操作将任意元素加1或减1，
求使所有元素相等的最小操作数
input:
5
3 1 4 1 5
output：
7
*/
//找中位数，求距离和
int main(){
    int n;
    cin>>n;
    vector<int > arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int ans=0;
    int mid=n/2;
    for(auto &it:arr){
        ans+=abs(it-arr[mid]);
    }
    cout<<ans<<endl;
}