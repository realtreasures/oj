#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool Is_same(string s1,string s2,string s3){
    int len1=s1.length();
    int len2=s2.length();
    //s1的前i个字符与s2的前j个字符
    vector<vector<bool>> dp(len1+1, vector<bool>(len2+1, false));
    dp[0][0]=true;
    if(s1.length()+s2.length()!=s3.length()){
        return false;
    }
    for(int i=1;i<=len1;i++){
        if(dp[i-1][0]&&s1[i-1]==s3[i-1]){
            dp[i][0]=true;
        }
    }
    for(int j=1;j<=len2;j++){
        if(dp[0][j-1]&&s2[j-1]==s3[j-1]){
            dp[0][j]=true;
        }
    }
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(dp[i-1][j]&&s1[i-1]==s3[i+j-1]){
                dp[i][j]=true;
            }
            if(dp[i][j-1]&&s2[j-1]==s3[i+j-1]){
                dp[i][j]=true;
            }
        }
    }
    return dp[len1][len2];
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s1;
        string s2;
        string s3;
        cin>>s1>>s2>>s3;
        if(Is_same(s1,s2,s3)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
