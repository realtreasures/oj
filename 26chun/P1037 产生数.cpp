

#include <bits/stdc++.h>
using namespace std;

__int128 ans=1;

// 输出 __int128 类型的整数
void print128(__int128 x) {
    if (x == 0) { // 如果答案是 0，直接输出 0
        cout << 0;
        return;
    }

    string res; // 用字符串暂存答案的每一位

    while (x > 0) { // 不断取末位数字
        res.push_back(char(x % 10 + '0')); // 把当前末位转成字符
        x /= 10; // 去掉最后一位
    }

    reverse(res.begin(), res.end()); // 因为是倒着存的，所以需要反转
    cout << res;
}

void f(vector<int> coun,string x){
    while(!x.empty()){
        char temp=x.back();
        int t=temp-'0';
        ans*=coun[t];
        x.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定
    string x;
    int n;
    cin>>x>>n;
    vector<vector<int>> a(10,vector<int>(10,0));
    vector<int> coun(10,0);


    for(int i=0;i<n;i++){
        int k,j;
        cin>>k>>j;
        a[k][j]=1;
    }
    //初始化
    for(int i=0;i<=9;i++){
        a[i][i]=1;
    }

    for(int k=0;k<=9;k++){
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                if(a[i][k]&&a[k][j]){
                    a[i][j]=1;
                }
            }
        }
    }

    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(a[i][j]){
                coun[i]++;
            }
        }
    }
    f(coun,x);

    print128(ans);

    return 0;
}