#include<bits/stdc++.h>
using namespace std;
int n,k,x[100],ok=0,s[100];
bool check(int a[],int b[]){
    for(int i = 1;i<=k;i++){
        if(a[i]!=b[i]) return 0;
    }
    return 1;
}


void ktao(){
    for(int i=1;i<=k;i++){
        x[i]=i;
    }
}
void sinh(){
    int i = k;
    while(i>=1&&x[i]==n-k+i) --i;
    if(i==0){
        ok=1;
    }else{
        x[i] = x[i] + 1;
        for(int j = i+1;j<=k;j++){
            x[j] = x[j-1]+1;
        }
    }
}
int main(){
    cin >> n >> k;
    int cnt = 1;
    ktao();
    for(int i = 1;i<=k;i++){
        cin >> s[i];
    }
    while(!ok){
        if(check(s,x)){
            cout << cnt;
            return 0;
        }
        ++cnt;
        sinh();
    }
}