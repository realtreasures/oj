#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INITIAL_LIFE 3

bool BFS(vector<vector<char>>& dungeon, int m, int n) {
    queue<pair<int, pair<int, int>>> q; // (x, (y, life))
    q.push({1, {1, INITIAL_LIFE}});

    // 记录每个位置的最大剩余血量，初始化为 -1
    vector<vector<int>> max_life(m + 1, vector<int>(n + 1, -1));
    max_life[1][1] = INITIAL_LIFE;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second.first;
        int life = q.front().second.second;
        q.pop();

        if (x == m && y == n) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 越界检查
            if (nx < 1 || ny < 1 || nx > m || ny > n) continue;

            // 不可通行地块检查
            if (dungeon[nx][ny] == 'W') continue;

            // 计算新血量
            int new_life = life;
            if (dungeon[nx][ny] == 'X') {
                new_life--;
            }

            // 血量不能为 0
            if (new_life <= 0) continue;

            // 如果新血量大于该位置记录的最大血量，则更新并加入队列
            if (new_life > max_life[nx][ny]) {
                max_life[nx][ny] = new_life;
                q.push({nx, {ny, new_life}});
            }
        }
    }

    return false;
}

int main() {
    int K, M, N;
    cin >> K >> M >> N;

    vector<vector<char>> dungeon(M + 1, vector<char>(N + 1));

    while (K--) {
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> dungeon[i][j];
            }
        }

        if (BFS(dungeon, M, N)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}