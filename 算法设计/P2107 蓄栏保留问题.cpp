#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    int n;
    int line=0;
    int ans=0;
    cin>>n;
    vector<int> arr(10001,0);
    for(int i=0;i<n;i++){
        int beg,end;
        cin>>beg>>end;
        arr[beg]++;
        //易错：因为是闭区间，所以要在结束时的下一个节点减去
        arr[end+1]--;
    }
    for(auto it:arr){
        line+=it;
        ans=max(ans,line);
    }
    cout<<ans<<endl;
    return 0;
}