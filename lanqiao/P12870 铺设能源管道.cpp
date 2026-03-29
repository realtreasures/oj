#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int i=0;
    int ans=1;
    int temp=n;
    while(temp!=0){
        temp=temp/10;
        i++;
    }
    while(i!=0){
        if(ans>=n){
            break;
        }
        ans*=10;
        
        i--;
        
    }
    cout<<ans<<endl;
    return 0;
}