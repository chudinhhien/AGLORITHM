#include<bits/stdc++.h>
using namespace std;
#define N 1005

vector<int> ke[N];
vector<int> topo;
bool visited[N];
int d[N];
int n,m;

void input(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        ke[x].push_back(y);
        ++d[y];
    }
    for(int i=1;i<=n;i++){
        sort(ke[i].begin(),ke[i].end());
    }
}

void Kahn(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(d[i]==0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int u = q.front();q.pop();
        topo.push_back(u);
        for(int v : ke[u]){
            --d[v];
            if(d[v]==0) q.push(v);
        }
    }
    if(topo.size()<n) cout << "Do thi co chu trinh!\n";
    else{
        for(int x : topo){
            cout << x << ' ';
        }
    }
}

int main(){
    input();
    Kahn();
}