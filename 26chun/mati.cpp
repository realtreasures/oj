#include<bits/stdc++.h> 

using namespace std;


int main( )
{
    int t;
    cin>>t;
    while(t--){
        int num;
        cin>>num;
        vector<int> a(num);
        for(int i=0;i<num;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int mex=0;
        for(int i=0;i<num;i++){
            if(a[i]==mex){
                mex++;
            }
        }
        cout<<mex;
        
    }
    return 0;
}