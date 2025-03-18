#include<bits/stdc++.h>
using namespace std;

//整除函数
void f(int n){
    if(n==1){
        cout<<1<<endl;
        return;
    }
    else{
        cout<<n<<' ';
        f(n/2);
    }
}

int main(){
    int n;
    cin>>n;
    f(n);
    return 0;
}
