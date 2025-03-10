
#include<iostream>
#include<queue>

using namespace std;

bool BFS(vector<vector<char>> num,int m,int n){
    queue<pair<pair<int,int>,int>> q;

    // 记录每个位置的最大剩余血量，初始化为 -1
    vector<vector<int>> max_life(m + 1, vector<int>(n + 1, -1));
    max_life[1][1] = 3;
    q.push({{1,1},3});
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        q.pop();

        if(x==m&&y==n){
            return true;
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            //越界检查
            if(nx>m||nx<=0||ny<=0||ny>n)
                continue;
            //"W"禁止同行    
            if(num[nx][ny]=='W')
                continue;
            int newlife=max_life[x][y];
            if(num[nx][ny]=='X'){
                if(newlife==1)
                continue;
                newlife--;
            }
            if(newlife>max_life[nx][ny]){
                max_life[nx][ny]=newlife;
                q.push({{nx,ny},max_life[nx][ny]});
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