#include<iostream>
using namespace std;
#define N 100005
int a[N]={0};
int main(){
    int j,k;
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int x;
        while(cin>>x){
            a[x]++;
            if(getchar()=='\n')
                break;
        }
    }
    int start=0,end=N-1;
    for(;start<N;start++){
        if(a[start]==0)
            continue;
        else
            break;
        }
    for(;end>0;end--){
        if(a[end]==0)
            continue;
        else
            break;
        }
    for(int i=start;i<=end;i++){
            if(a[i]==0){
                j=i;
            }
            if(a[i]==2){
                k=i;
            }
        }
    cout<<j<<" "<<k<<endl;
    return 0;
}