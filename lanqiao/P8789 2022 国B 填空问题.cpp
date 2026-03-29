#include <iostream>
using namespace std;

int ans = 0;

void dfs(int depth, int sum, int start) {
    if (depth == 10) {
        if (sum == 2022) ans++;
        return;
    }

    // 剩余的最小和都超过目标，剪枝
    int remaining = 10 - depth;
    int min_possible = sum + (start + start + remaining - 1) * remaining / 2;
    if (min_possible > 2022) return;

    for (int i = start; sum + i <= 2022; i++) {
        dfs(depth + 1, sum + i, i + 1); // i+1 保证互不相同
    }
}

int main() {
    dfs(0, 0, 1);
    cout << "DFS 解法结果: " << ans << endl;
    return 0;
}
