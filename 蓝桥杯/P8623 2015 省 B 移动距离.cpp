#include<iostream>
#include<map>
using namespace std;

map<int,pair<int,int>> arr;

int main(){
    int w,m,n;
    int ans;
    cin>>w>>m>>n;
    
    //要填的数
    int num=1;
    for(int i=0;i<=10000/w+1;i++){
        if(i%2==0){
            for(int j=0;j<w;j++){
                arr.insert({num++,{i,j}});
            }
        }
        else{
            for(int j=w-1;j>=0;j--){
                arr.insert({num++,{i,j}});
            }
        }
    }
    auto it1=arr.find(m);
    auto it2=arr.find(n);
    pair<int,int> pos1=it1->second;
    pair<int,int> pos2=it2->second;
    ans=abs(pos1.first-pos2.first)+abs(pos1.second-pos2.second);
    cout<<ans<<endl;
}