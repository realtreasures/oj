#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#define N 205
string add(string s1,string s2){
    string ans;
    int i,j;
    int tail=0;
    int len1=s1.size()-1;
    int len2=s2.size()-1;
    for(i=len1,j=len2;i>=0&&j>=0;i--,j--){
        int s=(s1[i]-'0')+(s2[j]-'0')+tail;
        ans.push_back(s%10+'0');
        tail=s/10;
    }
    while(i>=0){
        int s=(s1[i]-'0')+tail;
        ans.push_back((s)%10+'0');
        tail=(s)/10;
        i--;
    }   
    while(j>=0){
        int s=(s1[j]-'0')+tail;
        ans.push_back((s)%10+'0');
        tail=(s)/10;
        j--;
    }
    if(tail){
        ans.push_back(tail+'0');
    }
        // 结果是反向的，需要反转回来
        reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<add(s1,s2)<<endl;
    return 0;
}



/*
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string add(string s1, string s2) {
    string ans;
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    int carry = 0;

    // 从末尾开始逐位相加
    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? s1[i] - '0' : 0;  // 获取 s1 中当前位的数字
        int digit2 = (j >= 0) ? s2[j] - '0' : 0;  // 获取 s2 中当前位的数字
        
        int sum = digit1 + digit2 + carry;  // 当前位的和
        carry = sum / 10;  // 更新进位
        ans.push_back(sum % 10 + '0');  // 将当前位的数字加到结果字符串
        
        i--;
        j--;
    }

    // 结果是反向的，需要反转回来
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << add(s1, s2) << endl;
    return 0;
}
*/