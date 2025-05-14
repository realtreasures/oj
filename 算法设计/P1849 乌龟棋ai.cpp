#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // 输入得分数组 a
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 输入卡片类型数组 b
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    // 统计四种卡片的数量
    vector<int> cnt(5, 0); // cnt[0] 不使用, cnt[1-4] 对应四种卡片
    for (int i = 0; i < m; i++) {
        cnt[b[i]]++;
    }

    // 提取四种卡片的数量
    int cnt1 = cnt[1], cnt2 = cnt[2], cnt3 = cnt[3], cnt4 = cnt[4];

    // 初始化四维DP数组，所有元素初始为0
    vector<vector<vector<vector<int>>>> dp(cnt1 + 1, vector<vector<vector<int>>>(cnt2 + 1, vector<vector<int>>(cnt3 + 1, vector<int>(cnt4 + 1, 0))));

    // 初始状态：没有使用任何卡片，位于起点，得分为a[0]
    dp[0][0][0][0] = a[0];

    // 遍历所有可能的卡片使用状态
    for (int c1 = 0; c1 <= cnt1; c1++) {
        for (int c2 = 0; c2 <= cnt2; c2++) {
            for (int c3 = 0; c3 <= cnt3; c3++) {
                for (int c4 = 0; c4 <= cnt4; c4++) {
                    if (c1 == 0 && c2 == 0 && c3 == 0 && c4 == 0) {
                        continue;  // 初始状态已处理
                    }
                    // 计算当前位置
                    int pos = 1 + c1 * 1 + c2 * 2 + c3 * 3 + c4 * 4;
                    if (pos > n) {
                        continue;  // 跳过无效位置
                    }

                    int current_max = 0;
                    // 分别检查四种可能的前驱状态
                    if (c1 > 0) {
                        current_max = max(current_max, dp[c1 - 1][c2][c3][c4]);
                    }
                    if (c2 > 0) {
                        current_max = max(current_max, dp[c1][c2 - 1][c3][c4]);
                    }
                    if (c3 > 0) {
                        current_max = max(current_max, dp[c1][c2][c3 - 1][c4]);
                    }
                    if (c4 > 0) {
                        current_max = max(current_max, dp[c1][c2][c3][c4 - 1]);
                    }

                    // 更新当前状态的得分
                    dp[c1][c2][c3][c4] = current_max + a[pos - 1];
                }
            }
        }
    }

    // 最终状态是使用所有卡片，此时位置为n，输出得分
    cout << dp[cnt1][cnt2][cnt3][cnt4] << endl;

    return 0;
}
