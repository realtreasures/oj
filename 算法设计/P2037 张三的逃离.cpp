
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;

int dijkstra(int start, int n, const vector<vector<pii>>& graph) {
    vector<int> dist(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start}); // {distance, node}

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[n]; // distance to node n
}

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<vector<pii>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].emplace_back(v, d);
        graph[v].emplace_back(u, d); // undirected
    }

    int t_lx = dijkstra(x, n, graph); // LX 老师的时间
    int t_zhang = dijkstra(y, n, graph); // 张三的时间

    if (t_lx <= t_zhang)
        cout << "YES " << t_lx << '\n';
    else
        cout << "NO " << t_zhang << '\n';

    return 0;
}
