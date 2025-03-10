#include <bits/stdc++.h>
#define MAX 50
using namespace std;

const int direction[4][2] = {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0}
};
int k, n, m;

class Dungon{
public:
	int dungon[MAX][MAX], health_array[MAX][MAX];
	queue<pair<int, int>> bfs_queue;
	
	void load(){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				char c;
				int value;
				cin>>c;
				switch(c){
					case 'G':
						value = 0;
						break;
					case 'W':
						value = -1;
						break;
					default:
						value = 1;
						break;
				}
				dungon[i][j] = value;
				health_array[i][j] = 0;
			}
		}
	}
	
	void print_health(){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<health_array[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
	void bfs_traverse(int x, int y, int health){
		for (const auto& dir : direction) {
	        int next_x = x + dir[0];
	        int next_y = y + dir[1];
	        // Check boundaries
	        if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m)
	            continue;
	        // Check visited and obstacles
	        if (dungon[next_x][next_y] == -1)
	            continue;
	        
	        int next_health = health;
	    	// find a easy way
	        if (dungon[next_x][next_y] == 1)
	        	next_health--;
	        if (next_health <= 0)
	        	continue;
	        if (next_health > health_array[next_x][next_y]){
	        	health_array[next_x][next_y] = next_health;
				bfs_queue.push(make_pair(next_x, next_y));
			}
	    }
	}
	
	void bfs(int x = 0, int y = 0){
		bfs_queue.push(make_pair(x, y));
		health_array[x][y] = 3; // 初始生命值为3 
		
		while(!bfs_queue.empty()){
			//cout<<"while"<<endl;
			//print_visited(visited);
			//print_steps_array(steps_array);
			int x1 = bfs_queue.front().first, y1 = bfs_queue.front().second;
			bfs_queue.pop();
			if (health_array[x1][y1] > 0)
				bfs_traverse(x1, y1, health_array[x1][y1]);
		}
	}
	
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> k >> n >> m;
	while(k--){
		Dungon dungon;
		dungon.load();
		//dungon.print_dungon();
		dungon.bfs();
		//dungon.print_health();
		if (dungon.health_array[n-1][m-1] == 0){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
	}
	
	return 0;
}

/*
1 3 5
G G G X W
X X X G W
G G W G G

1 3 5
GGGXW
XXXGW
GGWGG
*/
