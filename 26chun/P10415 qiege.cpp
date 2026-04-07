#include<iostream>
#include<cmath>
#define int long long
using namespace std;

int gcd(int a,int b){
    while(b!=0){
        int temp = a%b;
        a=b;
        b=temp;
    }
    return a;
}

signed main(){
    int w,h;
    cin>>w>>h;
    int d=gcd(w,h);
    for(int i=2;i<=sqrt(d);i++){
        if(w%i==0&&h%i==0){
            cout<<w/i*h/i<<endl;
            return 0;
        }
    }
    if(d>=2){
        cout<<w/d*h/d<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
    return 0;
}