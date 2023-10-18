#include<bits/stdc++.h>
using namespace std;

int n,a[20];
int x[20];
vector<vector<int>> v;

void in(int i){
    for(int j=1;j<=i;j++){
        cout << x[j] << ' ';
    }
    cout << endl;
}

void Try(int i,int bd,int s){
    for(int j=bd;j<=n;j++){
        x[i] = a[j];
        if((s+a[j])%2==1){
            vector<int> tmp(x+1,x+i+1);
            v.push_back(tmp);
        }
        Try(i+1,j+1,s+a[j]);
    }
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    Try(1,1,0);
    sort(v.begin(),v.end());
    for(vector<int> tmp:v){
        for(int x:tmp){
            cout << x << ' ';
        }
        cout << endl;
    }
}