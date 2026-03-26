// 已知一个长方形的面积为 2025，且其长和宽均为正整数。
// 现在，请你计算这个长方形可能的最大周长是多少。

#include<iostream>

using namespace std;

int main(){
    int max_s=0;
    int a=1;
    for(;a<=2025;a++){
        int b=2025/a;
        if(a*b==2025){
            max_s=max(max_s,2*(a+b));
        }
    }
    cout<<max_s<<endl;
    return 0;
}