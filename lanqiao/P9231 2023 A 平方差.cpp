#include<iostream>
#include<cmath>
/*
题目描述：
给定L-R求x=y平方-z平方，有多少个
*/


using namespace std;

//除法运算
int chu(int l,int r){
    int count=0;
    for(int i=l;i<=r;i++){
        if(i%4==0||i%2==1){
            count++;
        }
    }
    return count;//不能整除
}

int main(){
    int l,r;//左右边界
    cin>>l>>r;
    int count=chu(l,r);
    cout<<count<<endl;
}