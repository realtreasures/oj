#include<iostream>
#include<cmath>

typedef long long ll;
using namespace std;
//判断是不是幸运数
bool Is_lucky(ll num){
    //判断位数是不是偶数
    int dex=floor(log10(num))+1;
    if(dex%2==0){
        int sum1=0,sum2=0;
        for(int i=1;i<=dex/2;i++){
            sum1+=(num%10);
            num/=10;
        }
        for(int i=dex/2+1;i<=dex;i++){
            sum2+=(num%10);
            num/=10;
        }
        if(sum1==sum2){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

int main(){
    int count=0;
    for(ll i=1;i<100000000;i++){
        if(Is_lucky(i)){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}