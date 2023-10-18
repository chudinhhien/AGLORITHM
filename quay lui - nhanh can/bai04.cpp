#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[16];
int x[16]={0};

void BackTrack(int i,int bd,int sum){
    for(int j=bd;j<=n;j++){
        x[i]=a[j];
        if(sum+a[j]==k){
            cout << '[';
            for(int u=1;u<=i-1;u++){
                cout << x[u] << ' ';
            }
            cout << x[i] << ']' << endl;
        }else if(sum+a[j]<k){
            BackTrack(i+1,j+1,sum+a[j]);
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    BackTrack(1,1,0);
}