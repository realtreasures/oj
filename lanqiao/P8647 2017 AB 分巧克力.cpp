#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
int main(){
    int num;//巧克力个数
    int kids;//小孩个数
    long long int count;//记录巧克力个数
    cin>>num>>kids;
    vector<int> h(num),w(num);//高和宽
    int maxn=0;//记录最大的边长，初筛
    for(int i=0;i<num;i++){
        cin>>h[i]>>w[i];
        maxn=max(maxn,max(h[i],w[i]));
    }
    int left=1,right=maxn;
    int ans;
    //二分
    while(left<=right){
        int mid=left+(right-left)/2;
        count=0;
        for(int i=0;i<num;i++){
            if(mid>h[i]||mid>w[i]){
                continue;
            }
            count+=(h[i]/mid)*(w[i]/mid);
        }
        if(count>=kids){
            ans=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}