
#include<bits/stdc++.h>

using namespace std;

int reverse(int x){
    int res=0;
    while(x!=0){
        res=res*10+x%10;
        x=x/10;
    }
    return res;
}

bool Is_huiwen(int x){
    if(x==reverse(x)){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    int n;
    int m;
    cin>>n>>m;
    
    int ans;
    for(int i=0;i<30;i++){
        if(Is_huiwen(m)){
            ans=i;
            break;
        }
        m=m+reverse(m);
    }
    if(ans<=30){
        cout<<"STEP="<<ans<<endl;
    }
    else{
        cout<<"Impossible!"<<endl;
    }
    
    return 0;
}