
#include<bits/stdc++.h>

using namespace std;

int x_[4]={1,0,-1,0};
int y_[4]={0,1,0,-1};
int flood=0;

int stream(int x,int y,vector<vector<char>> &mp,vector<vector<bool>> &flag){
    for(int i=0;i<4;i++){
        if(!flag[x][y]&&flag[x+x_[i]][y+y_[i]]&&mp[x][y]=='.'){
            return true;
        }
    }
    return false;
}

void xunhuan(int x,int y,vector<vector<char>> &mp,vector<vector<bool>> &flag){
    for(int i=0;i<4;i++){
        int xi=x+x_[i];
        int yi=y+y_[i];
        if(flag[xi][yi]||mp[xi][yi]=='#'){
                continue;
        }
        else if(mp[xi][yi]=='.'){
            flag[xi][yi]=true;
            flood++;
            xunhuan(xi,yi,mp,flag);
        }
    }
}

void hit(int x,int y,vector<vector<char>> &mp,vector<vector<bool>> &flag){
    if(stream(x,y,mp,flag)){
        flag[x][y]=true;
        flood++;
        xunhuan(x,y,mp,flag);
        return ;
    }
    return;

}

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<char>> mp(n+2,vector<char>(m+2,'.'));
    vector<vector<bool>> flag(n+2,vector<bool>(m+2,true));


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            flag[i][j]=false;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(stream(i,j,mp,flag)){
                flag[i][j]=true;
                flood++;
            };
        }
    }
    cout<<flood<<endl;
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        if(mp[x][y]=='#'){
            mp[x][y]='.';
            hit(x,y,mp,flag);
        }
        cout<<flood<<endl;
    }
    return 0;

}