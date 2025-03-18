#include<iostream>
#include<algorithm>
using namespace std;
int num[9]={1,2,3,4,5,6,7,8,9};
//判断是否整除
int f(int m,int n){
    if(m%n==0)
    return m/n;
    else
    return -1;
}

//计算大小
int computer(int *a,int start,int end){
    int s=0;
    for(int i=start;i<=end;i++){
        s=s*10+a[i];
    }
    return s;
}

int main(){
    int n;
    int count=0;//计数
    cin>>n;
    //保存整数，分子，分母
    int a,b,c;

    do{
        a=0;
        b=0;
        c=0;
        for(int i=0;i<=6;i++){
            for(int j=i+1;j<=7;j++){
                a=computer(num,0,i);
                b=computer(num,i+1,j);
                c=computer(num,j+1,8);
                if(f(b,c)==-1)
                continue;
                if(a+f(b,c)==n)
                count++;
            }
        }
    }while(next_permutation(num,num+9));
    cout<<count<<endl;

    return 0;
}