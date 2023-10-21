#include<bits/stdc++.h>
using namespace std;
#define N 10001


int n,m;
vector<int> ke[N];
bool visited[N];

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
    cout << u << ' ';
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
}

int main(){
    input();
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            DFS(i);
        }
    }
    return 0;
}