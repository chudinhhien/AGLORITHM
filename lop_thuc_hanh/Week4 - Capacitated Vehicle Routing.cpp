#include<bits/stdc++.h>
using namespace std;
#define N 100

int n,K,Q;
int d[N];//số lượng tải khách hàng yêu cầu
int X[N];//điểm tiếp theo của i
int Y[N];// điểm tiếp theo của điểm 0 trong hành trình thứ k
bool visited[N];
int c[N][N];//khoảng cách từ i đến j
int f;//tổng khoảng cách
int Fmin;//quảng đường ngắn nhất
int load[N];//Tải trong hành trình thứ k
int nbSegment;
vector<int> hanh_trinh[N];
int cnt = 0;

void input(){
    cin >> n >> K >> Q;
    for(int i=1;i<=n;i++) cin >> d[i];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cin >> c[i][j];
        }
    }
}

void solution(){
    ++cnt;
    for(int i=1;i<=K;i++){
        for(int x : hanh_trinh[i]){
            cout << x << ' ';
        }
        cout << endl;
    }
    cout << f << ' ';
    Fmin = min(f,Fmin);
    cout << Fmin << endl;
}

bool checkX(int i,int v,int k){
    if(v==0) return true;
    if(visited[v]) return false;
    if(load[k]+d[v]>Q) return false;
    return true;
}

bool checkY(int v,int k){
    if(visited[v]) return false;
    if(load[k]+d[v]>Q) return false;
    return true;
}

void TryX(int i,int k){//tìm điểm tiếp theo của i trong hành trình thứ k
    for(int v=0;v<=n;v++){
        if(checkX(i,v,k)){
            X[i] = v;
            hanh_trinh[k].push_back(v);
            visited[v] = true;
            f+=c[i][X[i]];
            load[k]+=d[v];
            nbSegment++;
            if(v==0){
                if(k<K){
                    TryX(Y[k+1],k+1);
                }
                else{
                    if(nbSegment==n+K) solution();
                }
            }else{
                TryX(v,k);
            }
            hanh_trinh[k].pop_back();
            visited[v] = false;
            f-=c[i][v];
            load[k]-=d[v];
            nbSegment--;
        }
    }
} 

void TryY(int k){ //tìm điểm tiếp theo của 0 của hành trình k
    for(int v=Y[k-1]+1;v<=n;v++){
        if(checkY(v,k)){
            Y[k] = v;
            hanh_trinh[k].push_back(v);
            visited[v] = true;
            f+=c[0][Y[k]];
            load[k]+=d[v];
            ++nbSegment;
            if(k==K){
                TryX(Y[1],1);
            }else{
                TryY(k+1);
            }
            hanh_trinh[k].pop_back();
            visited[v] = false;
            f-=c[0][Y[k]];
            load[k]-=d[v];
            --nbSegment;
        }
    }
}

int main(){
    f=0;Fmin=1e8;
    nbSegment=0;
    for(int v=1;v<=n;v++) visited[v] = false;
    for(int k=1;k<=K;k++) load[k] = 0;
    Y[0] = 0;
    input();
    TryY(1);
    cout << Fmin;
    cout << '\n' << cnt;
    return 0;
}