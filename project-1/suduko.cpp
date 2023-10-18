#include<bits/stdc++.h>
using namespace std;

int x[9][9];
int cnt = 0;

void input(){
    for(int i=0;i<=8;i++){
        for(int j=0;j<=8;j++){
            cin >> x[i][j];
        }
    }
}

bool check(int v,int r,int c){
    if(x[r][c]!=0) return false;
    for(int i=0;i<=8;i++){
        if(x[i][c]==v) return false;
    }
    for(int j=0;j<=8;j++){
        if(x[r][j]==v) return false;
    }
    int I = r/3; int J = c/3;
    for(int i1 = 0; i1 <= 2; i1++)
        for(int j1 = 0; j1 <= 2; j1++)
            if(x[3*I+i1][3*J+j1] == v) return false;
    return true;
}

void in(){
    for(int i=0;i<=8;i++){
        for(int j=0;j<=8;j++){
            cout << x[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void Try(int r, int c){
    if(x[r][c]==0){
        for(int v=1;v<=9;v++){
            if(check(v,r,c)){
                x[r][c] = v;
                if(r==8&&c==8) ++cnt;
                else{
                    if(c==8) Try(r+1,0);
                    else Try(r,c+1);
                }
                x[r][c]=0;
            }
        }
    }else{
        if(r==8&&c==8) ++cnt;
        else{
            if(c==8) Try(r+1,0);
            else Try(r,c+1);
        }
    }
}

int main(){
    input();
    Try(0,0);
    cout << cnt;
    return 0;
}
