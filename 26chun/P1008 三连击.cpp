
#include<bits/stdc++.h>

using namespace std;

void inser(set<int> &s,int x){
    for(int i=0;i<3;i++){
        int temp=x%10;
        if(temp==0){
            continue;
        }
        s.insert(temp);
        x/=10;
    }
}

int main(){
    for(int i=123;i<=987;i++){
        int doub=i*2;
        int tri=i*3;
        set<int> s;
        inser(s,i);
        inser(s,doub);
        inser(s,tri);
        if(s.size()==9){
            cout<<i<<" "<<doub<<" "<<tri<<endl;
        }
    }
    return 0;

}