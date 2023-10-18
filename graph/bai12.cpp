#include<bits/stdc++.h>
using namespace std;

int n,m,s;
vector<int> ke[1005];
bool visited[1005];

void input(){
    cin >> n >> m >> s;
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        ke[x].push_back(y);
    }
}

void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int x = q.front();q.pop();
        cout << x << ' ';
        for(int v : ke[x]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main(){
    input();
    for(int i=1;i<=n;i++){
        sort(ke[i].begin(),ke[i].end());
    }
    BFS(s);
}