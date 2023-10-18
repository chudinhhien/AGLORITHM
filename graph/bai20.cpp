#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> ke[1005];
bool visited[1005];
vector<pair<int,int>> canh;
int dem = 0;

void input(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        canh.push_back({x,y});
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        sort(ke[i].begin(),ke[i].end());
    }
}

void DFS(int u, int s, int t){
    visited[u] = true;
    for(int v : ke[u]){
        if((u==s&&v==t)||(u==t&&v==s))
            continue;
        if(!visited[v]){
            DFS(v,s,t);
        }
    }
}

int tplt(int s,int t){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            ++cnt;
            DFS(i,s,t);
        }
    }
    return cnt;
}

void canh_cau(){
    int cc = tplt(0,0);
    for(pair<int,int> e : canh){
        memset(visited,false,sizeof(visited));
        if(cc<tplt(e.first,e.second)){
            ++dem;
        }
    }
}

int main(){
    input();
    canh_cau();
    cout << dem;
    // for(pair<int,int> e : canh){
    //     cout << e.first << ' ' << e.second << '\n';
    // }
}