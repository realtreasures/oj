#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int n;
    int max_deep;//深度
    int max=0;
    int deep;
    cin>>n;
    vector<long long> num(n);//原始数组
    
    for(int i=0;i<n;i++){
        cin>>num[i];
    }

    //计算最深深度
    for(deep=1;pow(2,deep)-1<n;deep++){
    }
    for(int j=1;j<=deep;j++){//注意最后一层
        
        int s=0;
        for(int i=pow(2,j-1)-1;i<pow(2,j)-1&&i<n;i++){
            s+=num[i];
        }
        if(max<s){
            max=s;
            max_deep=j;
        }
    }
    cout<<max_deep<<endl;
    return 0;
}