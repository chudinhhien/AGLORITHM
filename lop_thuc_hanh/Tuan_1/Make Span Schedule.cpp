#include<bits/stdc++.h>
using namespace std;
#define N 10005

vector<int> ke[N];
bool visited[N];
stack<int> st;
int n,m;
int d[N];

void DFS(int u){
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
    st.push(u);
}

void input(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> d[i];
    while(m--){
        int x,y;
        cin >> x >> y;
        ke[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        sort(ke[i].begin(),ke[i].end());
    }
}

int main(){
    input();
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            DFS(i);
        }
    }
    while(!st.empty()){
        cout << st.top() << ' ';
        st.pop();
    }
}