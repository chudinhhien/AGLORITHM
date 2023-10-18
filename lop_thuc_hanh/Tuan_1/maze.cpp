#include<bits/stdc++.h>
using namespace std;
#define N 1005

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int n,m,r,c;
int A[N][N];
int ans = 1e8;
int dem = 0;

void input(){
    cin >> n >> m >> r >> c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> A[i][j];
        }
    }
}

void DFS(int i,int j){
    A[i][j] = 1;
    ++dem;
    if(i==1||j==1||i==n||j==m) ans = min(dem,ans); 
    for(int k=0;k<4;k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1>=1&&i1<=n&&j1>=1&&j1<=m&&A[i1][j1]==0){
            DFS(i1,j1);
        }
    }
    --dem;
    A[i][j] = 0;
}

int main(){
    input();
    DFS(r,c);
    cout << ans;   
}