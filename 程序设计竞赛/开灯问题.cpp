#include<iostream>

using namespace std;

#define N 10001
bool arr[N]={false};

bool f(int i,int k){
    int count=0;
    for(int j=1;j<=k;j++){
        if(i%j==0){
            count++;
        }
    }
    if(count%2==0){
        return false;
    }
    return true;
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        arr[i]=f(i,k);
    }
    for(int i=1;i<=n;i++){
        if(arr[i]){
            cout<<i<<endl;
        }
    }
    return 0;
}