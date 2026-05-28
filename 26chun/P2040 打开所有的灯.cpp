
#include<bits/stdc++.h>

using namespace std;

int n[5]={0,1,-1,0,0};
int m[5]={0,0,0,1,-1};
vector<vector<int>> used(5,vector<int>(5,0));

int ans=INT_MAX;

void change(int x,int y,vector<vector<int>>&a){
    for(int i=0;i<5;i++){
        a[x+n[i]][y+m[i]]=1-a[x+n[i]][y+m[i]];
    }
}

bool check(vector<vector<int>>&a){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(a[i][j]==0){
                return false;
            }
        }
    }
    return true;
}

void dfs(int steps,vector<vector<int>>&a){
    

    if(check(a)){
        ans=min(ans,steps);
    }
    if(steps>9){
        return;
    }

    for(int i=1;i<=3;i++){
        for(int  j=1;j<=3;j++){
            if(!used[i][j]){
                used[i][j]=1;
                change(i,j,a);
                dfs(steps+1,a);
                used[i][j]=0;
                change(i,j,a);

            }
        }
    }
}


int main(){
    vector<vector<int>>a(5,vector<int>(5,0));
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
    dfs(0,a);
    if(ans==INT_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }

}