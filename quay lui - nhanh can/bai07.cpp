#include<bits/stdc++.h>
using namespace std;

int cot[10],cheo1[10],cheo2[10];
int a[10][10];
int n = 8;
int ans = 0;

void Try(int i,int s){
    for(int j=1;j<=8;j++){
        if(!cot[j]&&!cheo1[n+i-j]&&!cheo2[i+j-1]){
            cot[j] = 1; cheo1[n+i-j] = 1; cheo2[i+j-1]=1;
            if(i==8){
                ans = max(ans,s+a[i][j]);
            }else{
                Try(i+1,s+a[i][j]);
            }
            cot[j] = 0;cheo1[n+i-j] = 0;cheo2[i+j-1] = 0;
        }
    }
}

int main(){
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            cin >> a[i][j];
        }
    }
    Try(1,0);
    cout << ans;
}