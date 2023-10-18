//C++ 
#include <bits/stdc++.h>
using namespace std;
#define N 100

int n,c[N][N],x[N];
bool visited[N];
int f,f_min=1e6,cmin=1e6;

void input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> c[i][j];
            if(c[i][j]!=0)
                cmin = min(cmin,c[i][j]);
        }
    }
}

bool check(int v,int k){
    return visited[v]==false;
}

void solution(){
    f_min = min(f_min,f+c[x[n]][1]);
}

void Try(int k){
    for(int v=1;v<=n;v++){
        if(check(v,k)){
            x[k] = v;
            visited[v] = true;
            f+=c[x[k-1]][x[k]];
            if(k==n){
                solution();
            }else if(f+cmin*(n-k+1)<f_min){
                Try(k+1);
            }
            f-=c[x[k-1]][x[k]];
            visited[v] = false;
        }
    }
}

int main() 
{ 
    input();
    f = 0;
    x[1] = 1;
    visited[1] = true;
    Try(2);
    cout << f_min;
    return 0;
}