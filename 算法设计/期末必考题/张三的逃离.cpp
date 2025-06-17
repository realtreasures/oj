#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        if (d < dist[u][v]) {
            dist[u][v] = d;
            dist[v][u] = d;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int t_lx = dist[x][n];
    int t_zhang = dist[y][n];

    if (t_lx <= t_zhang)
        cout << "YES " << t_lx << '\n';
    else
        cout << "NO " << t_zhang << '\n';

    return 0;
}