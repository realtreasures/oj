#include<iostream>
using namespace std;

void f(char &a){
    if(a=='*'){
        a='o';
    }
    else{
        a='*';
    }
}
int main(){
    string a,b;
    cin>>a>>b;
    int lenghth=a.length();
    int count=0;
    for(int i=0;i<lenghth;i++){
        if(a[i]!=b[i]){
            count++;
            f(a[i]);
            f(a[i+1]);
        }
    }
    cout<<count;
    return 0;
}