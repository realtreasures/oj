#include<bits/stdc++.h>

using namespace std;

int f(vector<int> &a,int i,int distance,int steps){
    if(i==(distance-1)){
        return steps;
    }
    else{
        if(a[i]==0){
            steps++;
            return f(a,i+1,distance,steps);
        }
        else{
            int take=f(a,i+a[i],distance,steps);
            int skip=steps+1+f(a,i+1,distance,steps+1);
            return min(take,skip);
        }
    }

}
int main(){
    int n,distance;
    cin>>n>>distance;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        arr[x]=y;
    }
    cout<<f(arr,0,distance,0)<<endl;
    return 0;
}