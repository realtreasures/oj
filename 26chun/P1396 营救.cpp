// 知识点：并查集，这次真得记住并查集的代码

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    int u, v, w;
};

// 按拥挤度从小到大排序
bool compareEdges(const Edge& a, const Edge& b){
    return a.w < b.w;
}

int fa[10005];

// 并查集查找（路径压缩）
int find(int x){
    if (fa[x] == x) 
        return x;
    
    fa[x] = find(fa[x]);
}

int main(){
    int n, m, s, t;
    cin>>n>>m>>s>>t;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // 排序
    sort(edges.begin(), edges.end(), compareEdges);

    // 初始化并查集
    for (int i = 1; i <= n; i++) fa[i] = i;

    // 按权值从小到大加边
    for (int i = 0; i < m; i++) {
        int rootU = find(edges[i].u);// 找 u 所在帮派的大佬
        int rootV = find(edges[i].v);// 找 v 所在帮派的大佬

        if (rootU != rootV) {        // 如果他们不属于同一个帮派
            fa[rootU] = rootV;      // 让 u 帮派的大佬 认 v 帮派的大佬当上级
        }

        // 检查起点和终点是否连通
        if (find(s) == find(t)){
            cout << edges[i].w << endl;
            return 0;
        }
    }

    return 0;
}