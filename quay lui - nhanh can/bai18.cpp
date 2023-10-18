#include<bits/stdc++.h>
using namespace std;

int cot[11],cheo1[11],cheo2[11];
int n,x[11];

void in(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(x[i]==j) cout << 'Q';
            else cout << '.';
        }
        cout << endl;
    }
    cout << endl;
}

void Try(int i){
    for(int j=1;j<=n;j++){
        if(!cot[j]&&!cheo1[n+i-j]&&!cheo2[i+j-1]){
            cot[j] = 1; cheo1[n+i-j] = 1 ; cheo2[i+j-1] = 1;
            x[i] = j;
            if(i==n){
                in();
            }else{
                Try(i+1);
            }
            cot[j] = 0; cheo1[n+i-j] = 0; cheo2[i+j-1] = 0;
        }
    }
}

int main(){
    cin >> n;
    Try(1);
}