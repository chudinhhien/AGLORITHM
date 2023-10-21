#include<bits/stdc++.h>
using namespace std;
#define N 10005

int n,m,r,c;
int a[N][N];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
map<pair<int,int>,int> mp;
int cnt;

void BFS(int i,int j){
    queue<pair<int,int>> Q;
    Q.push({i,j});
    a[i][j] = 1;
    mp[{i,j}]=1;
    while(!Q.empty()){
        auto x = Q.front();Q.pop();
        for(int k=0;k<4;k++){
            int i1 = x.first + dx[k];
            int j1 = x.second + dy[k];
            if(i1>=1&&i1<=n&&j1>=1&&j1<=m&&a[i1][j1]==0){
                Q.push({i1,j1});
                mp[{i1,j1}]=mp[x]+1;
                a[i1][j1] = 1;
                if(i1<=1||i1>=n||j1<=1||j1>=m){
                    cnt = mp[{i1,j1}];
                    return;
                }
            }
        }
    }
}

int main(){
    cin >> n >> m >> r >> c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    BFS(r,c);
    if(cnt==0) cout << "-1";
    else cout << cnt;
}