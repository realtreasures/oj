
#include<iostream>
#include<unordered_map>
using namespace std;

//二分查找
int find(int *a,int left,int right,int x){
    int mid=(left+right)/2;
    if(left>right){
        return -1;
    }
    else if(a[mid]==x){
        return mid;
    }
    else if(a[mid]>x){
        return find(a,left,mid-1,x);
    }
    else{
        return find(a,mid+1,right,x);
    }
}

int main(){
    int x,y,z;
    int n;
    cin>>x>>y>>z;
    cin>>n;
    unordered_map<int,int> a;
    a[0]=x;
    a[1]=y;
    for(int i=2;i<z;i++){
        a[i]=a[i/2]+a[i/4];
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(a.find())
        cout<<find(a,0,z-1,x)<<endl;
    }
    return 0;
}