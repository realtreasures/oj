#include<bits/stdc++.h>

using namespace std;
int a,n,m,x;

int shang(int n,int x){
    if(n==1){
        return a;
    }
    else if(n==2){
        return x;
    }
    else{
        return shang(n-2,x)+shang(n-1,x);
    }
}

int f(int n,int x){
    if(n==1){
        return a;
    }
    else if(n==2){
        return a;
    }
    else{
        return f(n-1,x)+shang(n-2,x);
    }
}


int main(){
    int init;
    cin>>a>>n>>m>>x;
    for(int i=1;i<=20;i++){
        if(f(n-1,i)==m){
            init=i;
            break;
        }
    }
    cout<<f(x,init)<<endl;

    return 0;
}