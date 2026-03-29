#include<iostream>
using namespace std;

int sum(int a){
    int s = 0;
    while(a!=0){
        s += a%10;
        a /= 10;
    }
    return s;
}

int main(){
    int n;
    int count=0;
    cin>>n;
    for(;n!=0;count++){
        n = n-sum(n);
    }
    cout<<count<<endl;
    return 0;
}