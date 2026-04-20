#include <iostream>
#include <algorithm>  // next_permutation 头文件
#include <string>     // 用string存01序列，最方便
using namespace std;

int main() {
    // 你的原始01序列（直接替换成任意01字符串即可）
    string s = "00101";
    
    // ✅ 关键步骤1：必须先排序！
    // 排序后变成最小字典序：0000000111111（所有0在前，1在后）
    sort(s.begin(), s.end());

    // ✅ 关键步骤2：循环遍历所有不重复全排列
    cout << "所有不重复的全排列：" << endl;
    int count = 0; // 统计排列总数
    do {
        cout << s << endl; // 输出当前排列
        count++;
    } while (next_permutation(s.begin(), s.end())); // 生成下一个不重复排列

    // 输出总数量
    cout << "\n排列总数：" << count << endl;
    return 0;
}