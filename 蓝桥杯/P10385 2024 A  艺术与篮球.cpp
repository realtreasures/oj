#include<iostream>
using namespace std;
int a[10]={13,1,2,3,5,4,4,2,2,2};
int IsRun(int year){
    if(year%4==0&&year%100!=0)
    return true;
    else if(year%400==0)
    return true;
    else 
    return false; 
}
int main(){
    int year=2000,month=1,day=1;
    for(;year<=2023;year++){
        for(;month<=12;month++){
            for(;day<=31;day++){
                
            }
        }
    }
}