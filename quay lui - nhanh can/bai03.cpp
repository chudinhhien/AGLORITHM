#include<bits/stdc++.h>
using namespace std;

int n;
int a[10][10];
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
string s = "DLRU";
string ans = "";
int check = 0;
int dem = 0;

void nhap(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
}

void Try(int i,int j){
    if(i==n&&j==n){
        ++dem;
        check = 1;
        cout << ans << endl;
    }
    for(int k=0;k<4;k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1>=1&&i1<=n&&j1>=1&&j1<=n&&a[i1][j1]){
            a[i1][j1] = 0;
            ans+=s[k];
            Try(i1,j1);
            a[i1][j1] = 1;
            ans.pop_back();
        }
    }
}
int main(){
    nhap();
    a[1][1] = 0;
    Try(1,1);
    if(check==0) cout << -1;
    cout << dem;
}