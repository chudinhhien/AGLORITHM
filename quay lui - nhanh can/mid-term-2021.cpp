#include<bits/stdc++.h>
using namespace std;

int n;
int x[100];     // HUST SOICT x[0] = H, x[1] = U, x[2] = S , x[3] = T, x[4] = O, x[5] = I ,x[6] = C
                // Lưu cấu hình
int cnt=0;
int visited[11];

bool check(int i,int j){
    if(i==0&&j==0) return false;
    if(i==2&&j==0) return false;
    if(visited[j]) return false;
    return true;
}

int tong(){
    int hust = x[0]*1000+x[1]*100+x[2]*10+x[3];
    int soict = x[2]*10000+x[4]*1000+x[5]*100+x[6]*10+x[3];
    return hust+soict;
}

void Try(int i){
    for(int j=0;j<10;j++){
        if(check(i,j)){
            x[i] = j;
            visited[j] = 1;
            if(i==6){
                if(tong()==n) ++cnt;
            }else{
                Try(i+1);
            }
            visited[j] = 0;
        }
    }
}

int main(){
    cin >> n;
    Try(0);
    cout << cnt;
}