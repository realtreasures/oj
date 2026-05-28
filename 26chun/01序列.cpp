

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;

    cin>>n;
    vector<int> s(n);
    for(auto &i:s){
        cin>>i;
    }
    char pre=s[0];
    int cnt=1;
    int max_cnt=1;
    for(int i=1;i<s.size();i++){
        if(s[i]!=pre){
            cnt++;
            pre=s[i];
        }
        else{
            max_cnt=max(cnt,max_cnt);
            cnt=1;

        }
    }
    max_cnt=max(max_cnt,cnt);
    cout<<max_cnt<<endl;
    return 0;
}