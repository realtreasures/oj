#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
//计算多少次可以超过life位
int f(ll x,int life){
    int count=1;
    //统计位数
    ll w=floor(log10(x)+1);
    if(w>life){
        return 0;
    }
    for(;;count++){
        if(count%2){
            w+=floor(log10(x));
            if(w>life)
            return count;
        }
        else{
            w+=floor(log10(x)+log10(count));
            if(w>life)
            return count;
        }
    }
}
int main(){
    ll x;
    int n;
    cin>>x>>n;
    for(int i=0;i<n;i++){
        int life;
        cin>>life;
        cout<<f(x,life)<<endl;
    }
    return 0;
}




/*
#include<iostream>

using namespace std;
#define N 100005

int function(int *num,int x,int life){
    int temp=x;
    int count=1;
    int end=0;
    while(temp){
        num[end++]=temp%10;
        temp=temp/10;
    }
    if(end>life){
        return 0;
    }
    for(;;count++){
        if(count%2){
            int tail=0;
            for(int i=0;i<end;i++){
                int w=num[i]*x+tail;
                num[i]=w%10;
                tail=w/10;
            }
            while(tail){
                num[end]=tail%10;
                end++;
                
                tail=tail/10;
            }
            if(end>life){
                break;
            }
        }
        else{
            int tail=0;
            for(int i=0;i<end;i++){
                int w=num[i]*x*count+tail;
                num[i]=w%10;
                tail=w/10;
            }
            while(tail){
                num[end]=tail%10;
                end++;
                
                tail=tail/10;
            }
            if(end>life){
                break;
            }
        }
    }
        
    return count;
}
int main(){
    int x,n,life;
    cin>>x>>n;
    for(int i=0;i<n;i++){
        int num[N];
        cin>>life;
        cout<<function(num,x,life)<<endl;
    }
    return 0;
}*/