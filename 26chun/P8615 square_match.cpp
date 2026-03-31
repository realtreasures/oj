/*# P8615 [蓝桥杯 2014 国 C] 拼接平方数

## 题目描述

小明发现 $49$ 很有趣，首先，它是个平方数。它可以拆分为 $4$ 和 $9$，拆分出来的部分也是平方数。$169$ 也有这个性质，我们权且称它们为：拼接平方数。

$100$ 可拆分 $1,00$，这有点勉强，我们规定，$0,00,000$ 等都不算平方数。

小明想：还有哪些数字是这样的呢？

你的任务出现了：找到某个区间的所有拼接平方数。

## 输入格式

两个正整数 $a,b(a<b<10^6)$。

## 输出格式

若干行，每行一个正整数。表示所有的区间 $[a,b]$ 中的拼接平方数，从小到大输出。

## 输入输出样例 #1

### 输入 #1

```
169 10000
```

### 输出 #1

```
169
361
1225
1444
1681
3249
4225
4900
9025
```

## 说明/提示

时限 1 秒, 256M。蓝桥杯 2014 年第五届国赛
*/
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<set>
using namespace std;

bool IsSquare(int x){

    if((int)sqrt(x)==sqrt(x)){
        return true;
    }
    return false;
}
int main(){
    int start,end;
    cin>>start>>end;
    vector<string> dict;
    set<int> ans;

    for(int i=1;i<=1000000;i++){
        if(IsSquare(i)){
            string temp = to_string(i);
            dict.push_back(temp);
        }
    }
    for(string front:dict){
        for(string back:dict){
            string temp = front+back;
            if (temp.length() > 7) continue;   // 避免溢出
            if(IsSquare(stoll(temp))&&stoll(temp)>=start&&stoll(temp)<=end){
                ans.insert(stoll(temp));
            }
        }
    }
    for(int i:ans){
        cout<<i<<endl;
    }
    return 0;


}