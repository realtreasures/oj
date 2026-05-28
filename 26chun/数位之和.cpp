
#include<bits/stdc++.h>

using namespace std;



int main(){
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        while(x!=0){
            int temp=x%10;
            x=x/10;
            ans+=temp;

        }
    }
    
    cout<<ans<<endl;
    return 0;
    
}