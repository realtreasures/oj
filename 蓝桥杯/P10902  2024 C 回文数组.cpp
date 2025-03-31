#include<iostream>

#include<vector>

using namespace std;

typedef long long ll;
int main(){
    ll n;
    cin>>n;
    ll count=0;
    vector<ll> arr(n+1);
    vector<ll> loss(n+1);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n%2==0){
        for(ll i=0,j=n/2;i<n/2;i++,j++){
            loss[i]=arr[i]-arr[j];
        }
        ll len=n/2;
        for(ll i=0;i<len-1;i++){
            if(loss[i]==0){
                continue;
            }
            else if((loss[i]>0&&loss[i+1]>0)){
                ll min_val=min(loss[i],loss[i+1]);
                count+=min_val;
                loss[i]-=min_val;
                loss[i+1]-=min_val;
                if(loss[i]==0&&loss[i+1]!=0){
                    continue;
                }
                else{
                    count+=loss[i];
                }
            }
            else if((loss[i]<0&&loss[i+1]<0)){
                ll x1=abs(loss[i]);
                ll x2=abs(loss[i+1]);
                ll min_val=min(x1,x2);
                count+=min_val;
                loss[i]+=min_val;
                loss[i+1]+=min_val;
                if(loss[i]==0&&loss[i+1]!=0){
                    continue;
                }
                else{
                    count+=abs(loss[i]);
                }
            }
            else if((loss[i]<0&&loss[i+1]>=0)){
                count+=abs(loss[i]);
            }
            else if(loss[i]>0&&loss[i+1]<=0){
                count+=loss[i];
            }
        }
        cout<<count+1<<endl;
    }

    else{
        for(ll i=0,j=n/2+1;i<n/2;i++,j++){
            loss[i]=arr[i]-arr[j];
        }
        ll len=n/2;
        for(ll i=0;i<len-1;i++){
            if(loss[i]==0){
                continue;
            }
            else if((loss[i]>0&&loss[i+1]>0)){
                ll min_val=min(loss[i],loss[i+1]);
                count+=min_val;
                loss[i]-=min_val;
                loss[i+1]-=min_val;
                if(loss[i]==0&&loss[i+1]!=0){
                    continue;
                }
                else{
                    count+=loss[i];
                }
            }
            else if((loss[i]<0&&loss[i+1]<0)){
                ll x1=abs(loss[i]);
                ll x2=abs(loss[i+1]);
                ll min_val=min(x1,x2);
                count+=min_val;
                loss[i]+=min_val;
                loss[i+1]+=min_val;
                if(loss[i]==0&&loss[i+1]!=0){
                    continue;
                }
                else{
                    count+=abs(loss[i]);
                }
            }
            else if((loss[i]<0&&loss[i+1]>=0)){
                count+=abs(loss[i]);
            }
            else if(loss[i]>0&&loss[i+1]<=0){
                count+=loss[i];
            }
        }
        cout<<count+1<<endl;
    }
    return 0;    
}