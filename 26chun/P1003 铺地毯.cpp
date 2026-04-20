#include<bits/stdc++.h>
using namespace std;

struct Carpet {
    int x, y, x_l, y_l;
};

int main(){
    int n;
    cin >> n;
    vector<Carpet> carpets(n);
    for(int i = 0; i < n; i++){
        cin >> carpets[i].x >> carpets[i].y >> carpets[i].x_l >> carpets[i].y_l;
    }
    int x, y;
    cin >> x >> y;
    int result = -1;
    // 逆序遍历，找到第一个覆盖点的地毯（最上层）
    for(int i = n-1; i >= 0; i--){
        if(x >= carpets[i].x && x <= carpets[i].x + carpets[i].x_l && 
           y >= carpets[i].y && y <= carpets[i].y + carpets[i].y_l){
            result = i+1; // 地毯编号从1开始
            break;
        }
    }
    cout << result << endl;
    return 0;
}