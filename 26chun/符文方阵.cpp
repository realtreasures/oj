#include<bits/stdc++.h> 

using namespace std;

int main( )
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(m*n,vector<int>(m));
    for(int i=0;i<m*n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<int>> c(m,vector<int>(m));
    int col=m*n-1;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            c[i][j]=a[col-m+i+1][j];
        }
    }
    col-=m;
    vector<vector<int>> c1(m,vector<int>(m));
    vector<vector<int>> temp(m,vector<int>(m));
    for(int k=0;k<n-1;k++){
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                c1[i][j]=a[col-m+i+1][j];
            }
        }
        col-=m;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                int s=0;
                for(int z=0;z<m;z++){
                    s=(s+c1[i][z]*c[z][j])%2;
                }
                temp[i][j]=s;
            }
        }
        c=temp;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<c[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}