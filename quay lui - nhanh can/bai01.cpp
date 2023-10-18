#include<bits/stdc++.h>
using namespace std;

int n,k,dem=0,s;
int a[21];

void Try(int i){
    for(int j=a[i-1]+1;j<=n-k+i;j++){
        a[i] = j;
        if(i==k){
            int tong=0;
            for(int j=1;j<=k;j++){
                tong+=a[j];
            }
            if(tong==s) ++dem;
        }else{
            Try(i+1);
        }
    }
}

int main(){
    cin >> n >> k >> s;
    Try(1);
    cout << dem;
}