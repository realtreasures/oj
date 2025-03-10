#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// 计算至少需要多少次 buff 才能超过怪物的血量位数
int f(ll x, int life) {
    int count = 1;
    // 计算初始伤害的位数
    double w = log10(x);
    
    // 如果初始伤害的位数已经超过怪物血量的位数，返回 0
    if (w > life) {
        return 0;
    }
    
    for (;;) {
        if (count % 2 == 1) {  // 如果是奇数次 buff
            w += log10(x);
        } else {  // 如果是偶数次 buff
            w += log10(x) + log10(count);
        }
        
        // 如果伤害的位数超过怪物血量的位数，返回施放的次数
        if (w > life) {
            return count;
        }
        
        // 增加 buff 次数
        count++;
    }
}

int main() {
    ll x;
    int n;
    cin >> x >> n;
    
    for (int i = 0; i < n; i++) {
        int life;
        cin >> life;
        cout << f(x, life) << endl;
    }
    
    return 0;
}
