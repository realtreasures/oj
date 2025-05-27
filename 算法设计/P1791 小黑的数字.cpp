#include<bits/stdc++.h>

using namespace std;

bool f(int n){
    while(n!=0){
        int x=n%10;
        n=n/10;
        if(x==4){
            return true;
        }
        if(x==6){
            x=n%10;
            if(x==2){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int left,right,count=0;
    cin>>left>>right;
    for(int i=left;i<=right;i++){
        if(!f(i)){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;

}