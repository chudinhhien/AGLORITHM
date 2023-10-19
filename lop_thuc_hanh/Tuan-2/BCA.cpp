#include<bits/stdc++.h>
using namespace std;
#define N 100

int m,n;  //n khóa học
          //m giáo viên
int x[N]; //lưu thông tin khóa học i đang được dạy bởi giáo viên x[i] nào
int load[N]; //lưu số khóa học giáo viên i đang dạy
int Fmin;//lưu tối thiểu của loadMax của giáo viên
int loadMax;
bool visited[N];//đánh dấu khóa học đã được dạy
bool c[N][N]={false};//c[i][j]=true => giáo viên i có thể dạy môn j
bool d[N][N]={false};//v[i][j]=true => khóa học i và j xung đột

void input(){
    cin >> m >> n;
    int k;
    for(int i=1;i<=m;i++){
        cin >> k;
        for(int j=1;j<=k;j++){
            int y;cin >> y;
            c[i][y]=true;
        }
    }
    cin >> k;
    for(int i=1;i<=k;i++){
        int a,b;cin >> a >> b;
        d[a][b]=true;d[b][a]=true;
    }
}

bool check(int v,int k){
    if(c[v][k]==false) return false;
    for(int i=1;i<=k-1;i++){
        if(x[i]==v){
            if(d[i][k]==true) return false;
        }
    }
    return true;
}

void in(){
    for(int i=1;i<=n;i++){
        cout << x[i] << ' ';
    }
    cout << endl;
}

void solution(){
    loadMax = -1;
    //in();
    for(int i=1;i<=m;i++){
        if(load[i]>loadMax) loadMax=load[i];
    }
    Fmin = min(Fmin,loadMax);
}


void Try(int k){
    for(int v=1;v<=m;v++){
        if(check(v,k)){
            x[k] = v;
            //cout << k << ':' << v << '\n';
            load[v]++;
            if(k==n){
                solution();
            }else if(load[v]<Fmin){
                Try(k+1);
            }
            load[v]--;
        }
    }
}

int main(){
    input();
    Fmin=1e9;
    Try(1);
    cout << Fmin;
    return 0;
}
