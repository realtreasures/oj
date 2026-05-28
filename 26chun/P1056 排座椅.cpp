#include <bits/stdc++.h>
using namespace std;

vector<int> seat1,seat2;
int m,n,k,l,d;


int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定
    cin>>m>>n>>k>>l>>d;
    seat1.resize(1000,0);
    seat2.resize(1000,0);
    for(int i=0;i<d;i++){
        int x,y,q,z;
        cin>>x>>y>>q>>z;
        if(x==q){
            seat2[min(y,z)]++;
        }
        else{
            seat1[min(x,q)]++;
        }
    }
    vector<int> row,col;
    for(int i=1;i<=m;i++){
        row.push_back(i);
    }
    for(int i=1;i<=n;i++){
        col.push_back(i);
    }
    sort(row.begin(),row.end(),[&](int a,int b){
        return seat1[a]>seat1[b];
    });
    sort(col.begin(),col.end(),[&](int a,int b){
        return seat2[a]>seat2[b];
    });

    vector<int> ans_row(row.begin(),row.begin()+k);
    vector<int> ans_col(col.begin(),col.begin()+l);
    sort(ans_row.begin(),ans_row.end());
    sort(ans_col.begin(),ans_col.end());

    for(int i=0;i<k;i++){
        cout<<ans_row[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<l;i++){
        cout<<ans_col[i]<<" "; 
    }


    

    return 0;
}
