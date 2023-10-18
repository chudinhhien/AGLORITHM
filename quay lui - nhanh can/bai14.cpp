#include<bits/stdc++.h>
using namespace std;

int n,s;
int a[101];
int x[101];
int dem = 0;
vector<vector<int>> v;

void BackTrack(int i,int bd,int sum){
    for(int j=bd;j<=n;j++){
        if(sum+a[j]<=s){
            x[i] = a[j];
            if(sum+a[j]==s){
                vector<int> tmp(x+1,x+i+1);
                v.push_back(tmp);
                ++dem;
            }else{
                BackTrack(i+1,j,sum+a[j]);
            }
        }else{
            return;
        }
    }
}

int main(){
    cin >> n >> s;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    BackTrack(1,1,0);
    if(dem==0){
        cout << -1;
    }else{
        cout << dem << endl;
        for(auto u:v){
            cout << '{';
            for(int i=0;i<=u.size()-1;i++){
                if(i<u.size()-1){
                    cout << u[i] << ' ';
                }else{
                    cout << u[i] << '}';
                }
            }
            cout << endl;
        }
    }
}