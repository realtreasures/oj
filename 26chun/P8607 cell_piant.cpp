#include<iostream>

using namespace std;

long long int jiao1(long long int n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 6;
    }
    return jiao1(n-1)*2+jiao1(n-2)*4;
}
long long int jiao2(long long int n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    return jiao2(n-1)*2;
}

long long int mid(long long int n){
    if(n==3){
        
    }
}

int main(){
    int n;
    cin>>n;

}