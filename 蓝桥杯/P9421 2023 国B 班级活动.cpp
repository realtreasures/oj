#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> a(100005,0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    int count1=0;
    int count2=0;
    for(auto it:a){
        if(it==1){
            count1++;
        }
        else if(it>2){
            count2+=(it-2);
        }
    }
    if(count1>count2){
        cout<<count2+(count1-count2)/2<<endl;
    }
    else{
        cout<<count1+(count2-count1)<<endl;
    }
    return 0;

}