#include<bits/stdc++.h>

using  namespace std;

int main(){
    long long int n;
    cin>>n;

    if(n==1){
        cout<<"1/1"<<endl;
        return 0;   
    }
    int u;
    for(int i=1;;i++){
        if(i*(i+1)/2>=n){
            u=i-1;
            break;
        }
    }
    int v=n-u*(u+1)/2;
    int x,y;
    u++;
    if(u%2==0){
        x=v;
        y=u-v+1;
    }
    else{
        x=u-v+1;
        y=v;
    }
    cout<<x<<"/"<<y<<endl;
    return 0;
}