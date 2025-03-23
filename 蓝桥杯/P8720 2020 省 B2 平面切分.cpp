#include<iostream>
#include<vector>
using namespace std;

//判重
void Is_same(vector<pair<int,int>> arr){
    
}
int main(){
    //表示几条直线
    int n;
    cin>>n;
    
    //存储斜率和截距
    vector<pair<int,int>> arr(n);

    //输入直线
    for(auto it:arr){
        cin>>it.first>>it.second;
    }

}