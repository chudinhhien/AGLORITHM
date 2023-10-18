#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> ke[1005];
bool visited[1005];

void input(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        sort(ke[i].begin(),ke[i].end());
    }
}

void DFS(int u){
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
}

int lt(){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            ++cnt;
            DFS(i);
        }
    }
    return cnt;
}

int main(){
    input();
    int dem = 0;
    int cc = lt();
    for(int i=1;i<=n;i++){
        memset(visited,false,sizeof(visited));
        visited[i] = true;
        if(cc<lt()) ++dem; 
    }
    cout << dem;
}