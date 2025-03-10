#include<iostream>
#include<queue>
using namespace std;

int f(int n){
    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while(q.size()>1){
        q.pop();
        q.push(q.front());
        q.pop();
    }
    return q.front();
}

//主函数
int main(){
    int T,n;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n;
        cout<<f(n)<<endl;
    }
}