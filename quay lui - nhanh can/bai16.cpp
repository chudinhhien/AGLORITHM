#include<bits/stdc++.h>
using namespace std;

int n;
char x[21];
int a[21];
string s;
vector<char> v[10];

void in(){
    for(int i = 1 ; i<=n;i++){
        cout << x[i];
    }
    cout << ' ';
}

void xuLy(){
    int idx = 2;
    for(char c='a';c<='z';c++){
        if(idx==7||idx==9){
            if(v[idx].size()==4) ++idx;
        }else{
            if(v[idx].size()==3) ++idx;
        }
        v[idx].push_back(c);
    }
}

void BackTrack(int i){
    for(int j = 0;j < v[a[i]].size(); j++){
        x[i] = v[a[i]][j];
        if(i==n){
            in();
        }else BackTrack(i+1);
    }
}

int main(){
    xuLy();
    cin >> s;
    n = s.length();
    int i = 1;
    for(char c:s){
        a[i] = (c - '0');
        ++i;
    }
    BackTrack(1);
}