//C++ 
#include <bits/stdc++.h>
using namespace std;

vector<int> ke[100005];
int n,m;
bool visited[100005];

void DFS(int u){
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
}

int main() 
{ 
    int cnt = 0;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            DFS(i);
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}