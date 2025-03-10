#include<iostream>
#include<vector>
using namespace std;

int L, N, row[5] = {0}, col[5] = {0}, ans = 0;

// 判断是否符合吉利矩阵
void back(int x) {
    // 如果已经填充完所有元素，检查是否符合要求
    if (x == N * N) {
        for (int i = 0; i < N; i++) {
            if (row[i] != L || col[i] != L) return;
        }
        ans++;
        return;
    }

    int r = x / N;  // 当前行
    int c = x % N;  // 当前列

    // 尝试每一个可能的填充值
    for (int i = 0; i <= L; i++) {
        // 剪枝1: 如果当前行或列和加上i后超过L，跳过
        if (row[r] + i > L || col[c] + i > L) continue;

        // 更新当前行和列的和
        row[r] += i;
        col[c] += i;

        // 剪枝2: 如果当前行或列已经无法满足L，提前结束
        if (row[r] + L * (N - 1 - c) >= L && col[c] + L * (N - 1 - r) >= L) {
            // 递归尝试下一个元素
        back(x + 1);
        }
        row[r] -= i;
        col[c] -= i;       
    }
}

int main() {
    cin >> L >> N;
    back(0);
    cout << ans << endl;
    return 0;
}
