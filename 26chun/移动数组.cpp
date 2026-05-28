
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> b(q);
    int x=0;
    for(int i=0;i<q;i++){
        cin>>b[i];
        if(b[i]==1){
            x+=1;

        }
        else{

            x-=1;
        }
    }
    
      x = (x % n + n) % n;

    // 向左旋转 x 位
    rotate(a.begin(), a.begin() + x, a.end());

    for(auto c:a){
        cout<<c<<' ';
    }

}