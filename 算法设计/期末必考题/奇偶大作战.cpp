#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int max_odd = 0, max_even = 0;
    int odd_count = 0, even_count = 0;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num % 2 == 1) {
            odd_count++;
            int cur = max_even + 1;
            if (cur > max_odd) {
                max_odd = cur;
            }
        } else {
            even_count++;
            int cur = max_odd + 1;
            if (cur > max_even) {
                max_even = cur;
            }
        }
    }
    
    int len_odd = max(max_odd, max_even);
    int len_even = max(odd_count, even_count);
    cout << len_odd - len_even << endl;
    
    return 0;
}