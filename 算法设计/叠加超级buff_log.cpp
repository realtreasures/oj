#include<iostream>
#include<cmath>
#include<map>
using namespace std;
/*
终于解决了在2025.3.17，21：25
一开始如果是对每个数都要算一遍就会超时，卡了我很久
最后，要先进行一次最大的遍历，把结果用二元组存在map里，
然后对于每个数都用upper_bound()查一下就出来了
也是成功过了
*/
map<int,int> num;
//存储位数
void f(int x){
    double dir=floor(log10(x))+1;
    int count;
    double logX=log10(x);
    num.insert({dir,0});
    dir=log10(x);
    for(count=1;floor(dir)+1<100002;count++){
        if(count%2==0)
        dir+=log10(count);
        dir+=logX;
        num.insert({floor(dir)+1,count});
    }
}

int main(){
    int x,y;
    cin>>x>>y;
    f(x);
    for(int i=0;i<y;i++){
        int di;
        cin>>di;
        auto it=num.upper_bound(di);
        cout<<it->second<<endl;
    }
    return 0;
}