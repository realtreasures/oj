#include <cstdio>
// 用cstdio的scanf/printf，速度比cin快100倍，适配1e5输入
int dp[25][25][25];

// 预处理所有0~20的结果，只计算一次
void init() {
    for (int a = 0; a <= 20; ++a) {
        for (int b = 0; b <= 20; ++b) {
            for (int c = 0; c <= 20; ++c) {
                if (a == 0 || b == 0 || c == 0) {
                    dp[a][b][c] = 1;
                } else if (a < b && b < c) {
                    dp[a][b][c] = dp[a][b][c-1] + dp[a][b-1][c-1] - dp[a][b-1][c];
                } else {
                    dp[a][b][c] = dp[a-1][b][c] + dp[a-1][b-1][c] + dp[a-1][b][c-1] - dp[a-1][b-1][c-1];
                }
            }
        }
    }
}

int main() {
    init();
    int a, b, c;
    // 极速读取输入
    while (scanf("%d%d%d", &a, &b, &c) != EOF) {
        if (a == -1 && b == -1 && c == -1) break;
        
        int ans;
        // 严格按题目优先级：先判断<=0，再判断>20
        if (a <= 0 || b <= 0 || c <= 0) {
            ans = 1;
        } else if (a > 20 || b > 20 || c > 20) {
            ans = dp[20][20][20];
        } else {
            ans = dp[a][b][c];
        }
        // 严格匹配输出格式！！！
        printf("w(%d, %d, %d) = %d\n", a, b, c, ans);
    }
    return 0;
}