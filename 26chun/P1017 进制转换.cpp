
#include<bits/stdc++.h>

using namespace std;

string transform(int num,int base){
    string ans="";
    while(num){
        int temp=num%base;
        num/=base;
        if(temp<0){
            temp-=base;
            num+=1;
        }
        if(temp>=10){
            char c=temp-10+'A';
            ans+=(char)c;
            continue;
        }
        ans+=to_string(temp);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    int num,base;
    cin>>num>>base;
    cout<<num<<"="<<transform(num,base)<<'('<<"base"<<base<<')'<<endl;
}