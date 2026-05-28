#include<bits/stdc++.h> 

using namespace std;

int main( )
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> c=a;
        int ans=0;
        sort(a.begin(),a.end(),greater<int>());
        for(int i=0;i<n;i++){
            if(a[i]==c[i]){
                ans++;
            }
        }
        cout<<n-ans<<endl;
    }
    return 0;
}