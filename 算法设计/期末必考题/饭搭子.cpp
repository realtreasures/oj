#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,w;
    cin>>n>>w;
    vector<int> stu(n);
    for(int i=0;i<n;i++){
        cin>>stu[i];
    }
    sort(stu.begin(),stu.end());
    int r=n-1;
    int l=0;
    int ans=0;
    while(r>l){
        if(stu[0]+stu[r]<=w){
            r--;
            l++;
        }
        else{
            r--;
        }
        ans++;
    }
    cout<<ans<<endl;
    return 0;

}