#include<bits/stdc++.h>
using namespace std;

//判断是否含有2,0,1,9
bool identify(int n){
    int copy_n=n;
    int flag=0;
    while(copy_n){
        int a=copy_n%10;
        if(a==2||a==0||a==1||a==9){
            flag=1;
            break;
        }
        copy_n/=10;
    }
    if(flag==1)
        return true;
    return false;
}

//累加
int add(int n){
    if(n==1)
        return 1;
    else if(identify(n)){
        return n+add(n-1);
    }
    else{
        return add(n-1);
    }
}
int main(){
    int n;
    cin>>n;
    cout<<add(n)<<endl;;
    return 0;
}