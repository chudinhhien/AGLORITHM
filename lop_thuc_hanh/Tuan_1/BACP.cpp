#include <bits/stdc++.h>
using namespace std;
#define N 20
int n,m;
int c[N],x[N];
int a[N][N];
int load[N];
int loadMin = 1e8;
int maxload = -1;

void input(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> c[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
}

bool check(int v,int k){
    for(int i=1;i<=k-1;i++){
        if(a[k][i]) // môn thứ k học trước môn thứ i 
            if(v>=x[i]) return false;
        else if(a[i][k])
            if(x[i]>=v) return false;
    }
    return true;
}

void solution(){
    maxload = -1;
    for(int i=1;i<=m;i++){
        maxload = max(maxload,load[i]);
    }
    loadMin = min(maxload,loadMin);
}

void Try(int k){
    for(int v=1;v<=m;v++){
        if(check(v,k)){
            x[k] = v; //môn k ở học kỳ v
            load[v]+=c[k]; //update tín chỉ
            if(k==n){
                solution();
            }else if(load[v]<loadMin){  //số tín chỉ học kỳ v nhỏ hơn kết quả mới có khả năng
                Try(k+1);
            }
            load[v]-=c[k];
        }
    }
}

int main() 
{ 
    input();
    Try(1);
    cout << loadMin;
    return 0;
}