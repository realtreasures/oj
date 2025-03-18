#include<iostream>
using namespace std;

bool f(int n,int t){
    if(n*n%t<t*0.5)
    return true;
    else
    return false;
}
int main(){
    int t,count=0;
    cin>>t;
    for(int i=1;i<t;i++){
        if(f(i,t)){
            count++;
        }
    }
    cout<<count<<endl;
}