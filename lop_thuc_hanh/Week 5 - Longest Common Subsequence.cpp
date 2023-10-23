//C++ 
#include <bits/stdc++.h>
using namespace std;
#define N 1005

int main() 
{ 
    int n,m;
    cin >> n >> m;
    int x[n+1],y[m+1];
    for(int i=1;i<=n;i++) cin >> x[i];
    for(int i=1;i<=m;i++) cin >> y[i];
    vector<vector<int>> S(n + 1, vector<int>(m + 1, 0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            S[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i]==y[j]){
                S[i][j] = S[i-1][j-1]+1;
            }else{
                S[i][j] = max(S[i-1][j],S[i][j-1]);
            }
        }
    }
    cout << S[n][m];
    return 0;
}