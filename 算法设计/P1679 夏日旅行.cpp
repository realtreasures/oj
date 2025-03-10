#include<iostream>
#include<queue>
using namespace std;

#define N 51

int findload(int info[N][N],int x1,int y1,int x2,int y2,int n,int m){
    //元素为二元组表示坐标
    queue<pair<int,int>> q;
    q.push({x1,y1});
    //步数统计
    int steps=0;
    bool label[N][N]={false};
    label[x1][y1]=true;
    while(!q.empty()){
        //队列当层的节点数
        int size=q.size();
        for(int i=0;i<size;i++){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            // 如果当前节点是目标点，返回步数
            if(x==x2&&y==y2)
                return steps;

            if(x-1>=1&&info[x-1][y]==0&&!label[x-1][y]){
                label[x-1][y]=true;
                q.push({x-1,y});
            }
            if(x+1<=n&&info[x+1][y]==0&&!label[x+1][y]){
                label[x+1][y]=true;
                q.push({x+1,y});
            }
            if(y-1>=1&&info[x][y-1]==0&&!label[x][y-1]){
                label[x][y-1]=true;
                q.push({x,y-1});
            }
            if(y+1<=m&&info[x][y+1]==0&&!label[x][y+1]){
                label[x][y+1]=true;
                q.push({x,y+1});
            }
        }
        steps++;
    }
    return -1;
}
int info[N][N];
int main(){
    int n,m;//矩阵的大小
    int x1,y1,x2,y2;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>info[i][j];
        }
    }
    cin>>x1>>y1>>x2>>y2;
    cout<<findload(info,x1,y1,x2,y2,n,m)<<endl;
    return 0;
}

/*
#include <iostream>
#include <queue>
using namespace std;

#define N 51

int findload(int info[N][N], int x1, int y1, int x2, int y2, int n, int m) {
    // 元素为二元组表示坐标
    queue<pair<int, int>> q;
    q.push({x1, y1});
    // 步数统计
    int steps = 0;
    bool label[N][N] = {false};
    label[x1][y1] = true;

    // 方向数组，表示上下左右四个方向
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        // 队列当层的节点数
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // 如果当前节点是目标点，返回步数
            if (x == x2 && y == y2) {
                return steps;
            }

            // 遍历四个方向
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                // 判断新位置是否合法，且未被访问过
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && info[nx][ny] == 0 && !label[nx][ny]) {
                    label[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        steps++;
    }
    return -1;
}

int info[N][N];

int main() {
    int n, m;  // 矩阵的大小
    int x1, y1, x2, y2;  // 起点和终点
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> info[i][j];
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;
    cout << findload(info, x1, y1, x2, y2, n, m) << endl;
    return 0;
}

*/