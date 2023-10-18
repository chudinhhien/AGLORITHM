#include<bits/stdc++.h>
using namespace std;

int n,m,s,t;
vector<int> ke[1005];
bool visited[1005];
int parent[1005];
vector<int> truy_vet;

void input(){
    cin >> n >> m >> s >> t;
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

void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int x = q.front();q.pop();
        for(int v : ke[x]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
                parent[v] = u;
            }
        }
    }
}

int main(){
    input();
    BFS(s);
    if(!visited[t]){
        cout << "-1";
    }else{
        while(t!=s){
            truy_vet.push_back(t);
            t = parent[t];
        }
        truy_vet.push_back(s);
        reverse(truy_vet.begin(),truy_vet.end());
        for(int x:truy_vet){
            cout << x << ' ';
        }
    }
}