#include<iostream>
#include<cmath>
/*
题目描述：
给定L-R求x=y平方-z平方，有多少个
*/
using namespace std;

//除法运算
int chu(int x,int d){
    if(x%d==0){
        return x/d;
    }
    return -1;//不能整除
}

//判断是不是同时为奇数或偶数
bool Is_same(int j,int j_match){
    if(j%2==j_match%2){
        return true;
    }
    return false;
}

int main(){
    int l,r;//左右边界
    int count=0;
    cin>>l>>r;
    for(int i=l;i<=r;i++){
        for(int j=1;j<=sqrt(i);j++){
            int j_match=chu(i,j);
            if(j_match!=-1){
                if(Is_same(j,j_match)){
                    count++;
                }
            }
        }
    }
    cout<<count<<endl;
}