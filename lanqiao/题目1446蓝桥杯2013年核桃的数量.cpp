#include<iostream>
using namespace std;
int f(int a,int b){
    if(a%b==0)
    return a;
    else if(b%a==0)
    return b;
    else
    return -1;
}
int main()
{
    int a,b,c;
    int num;
    cin>>a>>b>>c;
    int m=f(a,b);
    if(m>0){
        if(f(m,c)>0){
            printf("%d",f(m,c));
        }
        else
        printf("%d",m*c);
    }
    else{
        int n=a*b;
        if(f(n,c)>0){
            printf("%d",f(n,c));
        }
        else
        printf("%d",n*c);
    }
    return 0;
}