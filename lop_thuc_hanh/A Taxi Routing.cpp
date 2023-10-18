#include<bits/stdc++.h>
using namespace std;
#define N 1000

int n;
int c[N][N];
int x[N];
int T;
int Fmin = 1e9;
int cmin = 1e9;
int cap = 0;
bool visited[N];

void input(){
    cin >> n;
    for(int i=0;i<=2*n;i++){
        for(int j=0;j<=2*n;j++){
            cin >> c[i][j];
            if(c[i][j]!=0) cmin = min(cmin,c[i][j]);
        }
    }
}

bool check(int v,int k){
    if(visited[v]) return false;
    if(v<=n){
        if(cap==1) return false;
    }else{
        //Nếu v>n: nghĩa là đến điểm trả khách nhưng nếu mà chưa lấy được hàng thì khá nguy
        if(!visited[v-n]) return false;
    }
    return true;
}

void solution(){
    Fmin = min(T+c[x[2*n]][0],Fmin);
}

void Try(int k){
    for(int v=1;v<=2*n;v++){
        if(check(v,k)){
            if(v<=n) cap = 1; //Nếu là điểm lấy hàng tăng cap lên 1
            else cap = 0;     //Ngược lại là điểm trả hàng thì giảm cap đi 0
            x[k] = v;
            T+=c[x[k-1]][v];
            visited[v] = true;
            if(k==2*n){
                solution();
            }else if((T+(2*n+1-k)*cmin)<Fmin){
                Try(k+1);
            }
            T-=c[x[k-1]][v];
            visited[v] = false;
            if(v<=n) cap = 0;
            else cap = 1;
        }
    }
}

int main(){
    input();
    x[0] = 0;
    T = 0;
    Try(1);
    cout << Fmin;
    return 0;
}