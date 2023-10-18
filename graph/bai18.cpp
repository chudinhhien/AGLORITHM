#include<bits/stdc++.h>
using namespace std;

int n,m;
int dem = 0;
vector<int> ke[1005];
bool visited[1005];
int lt[1005];
int q;

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
    lt[u] = dem;
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
            ++dem;
            DFS(i);
        }
    }
    cin >> q;
    while(q--){
        int i,j;
        cin >> i >> j;
        if(lt[i]==lt[j]){
            cout << "1\n";
        }else{
            cout << "-1\n";
        }
    }
}