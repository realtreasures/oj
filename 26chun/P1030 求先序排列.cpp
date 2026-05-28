// 二分加递归

#include <bits/stdc++.h>
using namespace std;

string build(string zhong,string hou){
    if(zhong.empty()){
        return "";
    }
    char root=hou[hou.size()-1];

    int index=zhong.find(root);

    string left=zhong.substr(0,index);
    string right=zhong.substr(index+1);
    string left_hou=hou.substr(0,index);
    string right_hou=hou.substr(index);
    right_hou.pop_back();
    return root+build(left,left_hou)+build(right,right_hou);
}

int main() {
    ios::sync_with_stdio(false); // 关闭同步，加快输入输出
    cin.tie(nullptr); // 解除 cin 和 cout 的绑定
    string zhong,hou;

    cin>>zhong>>hou;

    cout<<build(zhong,hou)<<endl;   

    return 0;
}