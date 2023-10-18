#include<bits/stdc++.h>
using namespace std;

int n,c[100][100],x[100], ans = INT_MAX,used[100],cmin=INT_MAX;

void BackTrack(int i,int s){
    for(int j=2;j<=n;j++){
        if(!used[j]){
            x[i] = j;
            used[j] = 1;
            if(i==n){
                ans = min(ans,s+c[x[i-1]][j]+c[j][1]);
            }else if(s+c[x[i-1]][j]+(n-i+1)*cmin<ans){
                BackTrack(i+1,s+c[x[i-1]][j]);
            }
            used[j] = 0;
        }
    }
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> c[i][j];
            if(c[i][j]>0) cmin=min(cmin,c[i][j]);
        }
    }
    x[1] = 1;
    BackTrack(2,0);
    cout << ans;
}