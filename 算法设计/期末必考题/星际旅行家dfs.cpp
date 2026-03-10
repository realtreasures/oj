#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    if(visited[node]==true){
        return ;
    }
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int main() {
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // 从1号星球开始递归DFS
    dfs(1, graph, visited);
    
    int unreachable = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            unreachable++;
        }
    }
    
    cout << unreachable << endl;
    
    return 0;
}