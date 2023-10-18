#include<bits/stdc++.h>
using namespace std;

int n,a[13][13];
string s = "";
int check = 0;

void nhap(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
}

void BackTrack(int i,int j){
    if(i==n&&j==n){
        check = 1;
        cout << s << endl;
    }
    if(i+1<=n&&a[i+1][j]==1){
        a[i+1][j] = 0;
        s+="D";
        BackTrack(i+1,j);
        a[i+1][j] = 1;
        s.pop_back();
    }
    if(j+1<=n&&a[i][j+1]){
        a[i][j+1] = 0;
        s+="R";
        BackTrack(i,j+1);
        a[i][j+1] = 1;
        s.pop_back();
    }
}
int main(){
    nhap();
    BackTrack(1,1);
    if(check==0){
        cout << -1;
    }
}