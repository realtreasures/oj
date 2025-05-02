#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;  // 读取学生总数

    vector<pair<int, string>> students(N);  // 用来存储学生的性别和姓名，pair的第一个元素是性别，第二个是姓名

    // 读取学生信息
    for (int i = 0; i < N; ++i) {
        int gender;
        string name;
        cin >> gender >> name;
        students[i] = {gender, name};
    }

    int i = 0, j = N - 1;
    while (i < j) {
        // 找到男女异性配对
        if (students[i].first != students[j].first) {
            // 输出结果，名次高的在前
            cout << students[i].second << " " << students[j].second << endl;
            i++;  // 处理下一个名次靠前的学生
            j--;  // 处理下一个名次靠后的学生
        } else {
            // 如果性别相同，跳过当前这两个学生，继续寻找配对
            if (students[i].first == 0) i++;  // 女生跳到下一个
            else j--;  // 男生跳到下一个
        }
    }

    return 0;
}
