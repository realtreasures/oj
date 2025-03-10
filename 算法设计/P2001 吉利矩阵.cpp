#include<iostream>
#include<vector>
using namespace std;
int L,N,row[5]={0},col[5]={0},ans=0;
//判断是否符合吉利矩阵
void back(int x){
    if(x==N*N){
        for(int i=0;i<N;i++){
            if(row[i]!=L||col[i]!=L)
            return;
        }
        ans++;
        return;
    }
    for(int i=0;i<=L;i++){
        if(row[x/N]+i>L||col[x%N]+i>L)
            continue;
        //更新行和列的和
        row[x/N]+=i;
        col[x%N]+=i;
        //如果剩下的空填入最大值可以大于等于L则递归下一个
        if(row[x/N]+L*(N-1-x%N)>=L&&col[x%N]+L*(N-1-x/N)>=L)
            back(x+1);
        
        //回溯
        row[x/N]-=i;
        col[x%N]-=i;
    }
}
int main(){
   
    cin>>L>>N;
    back(0);
    cout<<ans<<endl;
    return 0;
}