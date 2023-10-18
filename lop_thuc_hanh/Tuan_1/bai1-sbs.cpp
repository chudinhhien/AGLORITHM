#include<bits/stdc++.h>
using namespace std;

int a[1000];
int x[1000];
int T;
int cnt = 1;
int m;
int amin = 1e8;
int check1 = 0;

bool check(int v,int k){
    return true;
}

void solv(){
    cout << '[';
    for(int i=1;i<=cnt;i++){
        if(i<cnt) cout << x[i] << ',';
        else cout << x[i] << ']';
    }
}

void Try(int k){
    for(int v=0;v<=m/amin;v++){
        if(check(v,k)){
            x[k] = v;
            T+=x[k]*a[k];
            if(k==cnt){
                if(T==m){
                    check1 = 1;
                    solv();
                }
            }else Try(k+1);
            T-=x[k]*a[k];
        }
    }
}

int main(){
    string s;
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]==')'||s[i]==',') s[i] = ' '; 
    }
    stringstream ss(s);
    string tmp;
    while(ss >> tmp){
        a[cnt] = stoi(tmp);
        amin = min(amin,a[cnt]);
        ++cnt;
    }
    m = a[cnt-1];
    cnt = cnt - 2;
    T = 0;
    Try(1);
    if(check1==0) cout << (m/amin+1)*amin;
    return 0;
}