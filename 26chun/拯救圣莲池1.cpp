
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    long long ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    queue<int> q;
    for(auto c:a){
        q.push(c);
    }

    int temp=q.front();
    for(int i=0;i<k;i++){
        ans+=temp;
        temp--;
        if(temp==0){
            q.pop();
            temp=q.front();
        }
        
    }
    cout<<ans<<endl;
    return 0;
}