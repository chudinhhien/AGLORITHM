#include<bits/stdc++.h>
using namespace std;

int n,m,s;
vector<int> ke[1005];
bool visited[1005];

void DFS(int u){
    cout << u << ' ';
    visited[u] = true;
    for(int v:ke[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
}

int main(){
    cin >> n >> m >> s;
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        ke[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        sort(ke[i].begin(),ke[i].end());
    }
    DFS(s);
}