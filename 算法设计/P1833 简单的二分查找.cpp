#include<iostream>

using namespace std;

void double_find(long long int x,long long int y,long long int z){
    long long int mid;
    if((x+y)%2==0){
        mid=(x+y)/2;
    }
    else{
        mid=(x+y-1)/2;
    }
    if(mid==z){
        cout<<'G'<<endl;
    }
    else if(mid>z){
        cout<<'L';
        double_find(x,mid-1,z);
    }
    else{
        cout<<'R';
        double_find(mid+1,y,z);
    }

}

int main(){
    long long int x,y,z;
    cin>>x>>y>>z;
    double_find(x,y,z);
    return 0;
}