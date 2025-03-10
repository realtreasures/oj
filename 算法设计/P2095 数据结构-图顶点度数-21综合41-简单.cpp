#include<iostream>
#include<vector>
using namespace std;

int main(){
    //n为n*n矩阵，count记录度为0或者为2的次数
    int n,count=0;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n));
    //记录每行的和
    vector<int> row(n,0);
 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            row[i]+=a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(row[i]%2==1)
            count++;
    }
    if(count==0||count==2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}