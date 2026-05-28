#include<bits/stdc++.h> 

using namespace std;

int main( )
{
    int n;
    cin>>n;
    int s=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if((i/2)%2==0){
            s+=x;

        }
        else{
            s-=x;

        }
    }
    cout<<s<<endl;
    return 0;
}