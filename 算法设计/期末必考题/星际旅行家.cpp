#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;
    
    // 邻接表存储图结构
    vector<vector<int>> graph(n + 1);
    // 访问标记数组
    vector<bool> visited(n + 1, false);
    
    // 构建星门连接
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // 无向图，双向连接
    }
    
    // 从1号星球开始BFS遍历
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        // 遍历当前星球的所有邻居
        for (int neighbor : graph[cur]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
    // 统计无法到达的星球数量
    int unreachable = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            unreachable++;
        }
    }
    
    cout << unreachable << endl;
    
    return 0;
}