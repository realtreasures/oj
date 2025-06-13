#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2e6 + 10; // 比 1e6 多一些，避免越界

vector<int> parent(MAX);

// 初始化：每个数最小可用的是自己
void init() {
    for (int i = 0; i < MAX; ++i)
        parent[i] = i;
}

// 查找当前数字的最小可用值
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N), res(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    init(); // 初始化并查集

    for (int i = 0; i < N; ++i) {
        int val = find(A[i]);   // 找最小可用值
        res[i] = val;
        parent[val] = find(val + 1); // 占用该值，更新父节点
    }

    for (int i = 0; i < N; ++i) cout << res[i] << " ";
    cout << endl;

    return 0;
}
