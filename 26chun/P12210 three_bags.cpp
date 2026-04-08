#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long B[3];
        cin >> B[0] >> B[1] >> B[2];

        int cntA, cntB;
        cin >> cntA >> cntB;

        long long VA, VB;
        cin >> VA >> VB;

        long long ans = 0;

        // 每个背包最多放多少A
        long long maxA[3];
        for (int i = 0; i < 3; i++) {
            maxA[i] = B[i] / VA;
        }

        for (int a = 0; a <= cntA; a++) {
            if (a > maxA[0] + maxA[1] + maxA[2]) break;

            for (int a1 = 0; a1 <= min((long long)a, maxA[0]); a1++) {
                for (int a2 = 0; a2 <= min((long long)(a - a1), maxA[1]); a2++) {
                    long long a3 = a - a1 - a2;
                    if (a3 < 0 || a3 > maxA[2]) continue;

                    long long leftB = cntB;
                    long long totalB = 0;

                    for (int i = 0; i < 3; i++) {
                        long long ai = (i == 0 ? a1 : (i == 1 ? a2 : a3));
                        long long rest = B[i] - ai * VA;
                        long long bi = min(leftB, rest / VB);
                        totalB += bi;
                        leftB -= bi;
                    }

                    ans = max(ans, (long long)a + totalB);
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}