#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
int main(){
    int n,m;
    cin>>n>>m;
    vector<pii> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    int steps=0;
    int max_dis=0;
    int i;
    for(i=0;i<n;i++){
        if(max_dis>=m){
            cout<<steps<<endl;
            exit(0);
        }
        else if(max_dis<a[i].first){
            steps+=(a[i].first-max_dis);
            max_dis=a[i].first+a[i].second;
        }
        else{
            if(max_dis<a[i].first+a[i].second){
                max_dis=a[i].first+a[i].second;
            }
        }
    }
    if(max_dis<m){
        steps+=(m-max_dis);
    }
    cout<<steps<<endl;
}