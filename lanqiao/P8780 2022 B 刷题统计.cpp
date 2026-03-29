#include<iostream>
using namespace std;

int main(){
    long long int a,b,n;
    cin>>a>>b>>n;
    long long int s=a*5+b*2;
    long long int count=n/s*7;
    long long int yu=n%s;
    if(yu>0&&yu<=a){
        count+=1;
    }
    else if(yu>a&&yu<=2*a){
        count+=2;
    }
    else if(yu>2*a&&yu<=3*a){
        count+=3;
    }
    else if(yu>3*a&&yu<=4*a){
        count+=4;
    }
    else if(yu>4*a&&yu<=5*a){
        count+=5;
    }
    else if(yu>5*a&&(yu-5*a)<=b){
        count+=6;
    }
    else{
        count+=7;
    }
    cout<<count<<endl;    
    return 0;
}