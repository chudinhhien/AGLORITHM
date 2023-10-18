#include<bits/stdc++.h>
using namespace std;

int n,x[100],cot[100],cheo1[100],cheo2[100],dem=0;

void Try(int i){
    for(int j=1;j<=n;j++){
        if(cot[j]==0&&cheo1[n+i-j]==0&&cheo2[i+j-1]==0){
            x[i] = j;
            cot[j] = 1; cheo1[n+i-j] = 1 ; cheo2[i+j-1]=1;
            if(i==n){
                ++dem;
            }else{
                Try(i+1);
            }
            cot[j] = 0; cheo1[n+i-j] = 0 ; cheo2[i+j-1] = 0;
        }
    }
}

int main(){
    cin >> n;
    Try(1);
    cout << dem;
}