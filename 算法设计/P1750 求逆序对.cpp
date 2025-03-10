#include<bits/stdc++.h>

using namespace std;

//合并函数
long long int co_merge(vector<int>& arr,int left,int right,int mid){
    //临时数组
    vector<int> temp(right-left+1);
    long long int ans=0;
    int i=left;
    int j=mid+1;
    int k=0;
    for(;i<=mid&&j<=right;){
        if(arr[i]<=arr[j]){//这得是小于等于
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            ans+=(mid-i+1);
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }

    //把有序临时数组复制到arr中
    for(int i=left,j=0;i<=right;i++,j++){
        arr[i]=temp[j];
    }
    return ans;
}

//归并排序
long long int merge(vector<int>& arr,int left,int right){
    if(left>=right){
        return 0;
    }
    long long int count=0;
    int mid=(left+right)/2;
    count+=merge(arr,left,mid);
    count+=merge(arr,mid+1,right);
    count+=co_merge(arr,left,right,mid);
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<merge(arr,0,n-1)<<endl;
    return 0;
}
