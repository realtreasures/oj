#include<iostream>
using namespace std;

int f(int *num,int start,int n){
    int max=num[start],min=num[start]; 
    int count=0;
    for (int end = start; end < n; end++) {
        max = std::max(max, num[end]);
        min = std::min(min, num[end]);
        if ((max - min) == (end - start)) {
            count++;
        }
    }
    return count;
}
int main(){
    int n,a[50005];
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        ans+=f(a,i,n);
    }
    cout<<ans<<endl;
}