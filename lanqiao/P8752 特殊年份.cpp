#include<iostream>
using namespace std;
int main(){
    int count=0,year;
    for(int i=0;i<5;i++){
        cin>>year;
        int d=year%10;
        int c=year/10%10;
        int b=year/100%10;
        int a=year/1000;
        if(a==c&&d-1==b)
        count++;
    }
    cout<<count<<endl;
}