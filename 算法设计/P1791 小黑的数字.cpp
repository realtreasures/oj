#include<bits/stdc++.h>

using namespace std;

bool Is_hei(int n){
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
    vector<int> dp(10000005);
    int left,right,count=0;
    cin>>left>>right;
    for(int i=left;i<=right;i++){
        if(!Is_hei(i)){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;

}