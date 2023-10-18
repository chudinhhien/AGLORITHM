#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t;
    cin >> n >> t;
    int a[n+1][n+1]={0};
    while(t--){
        int i,j;
        cin >> i >> j;
        a[i][j] = 1;
        a[j][i] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}