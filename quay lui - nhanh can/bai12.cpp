#include<bits/stdc++.h>
using namespace std;

int a[21],x[21];
int n;
int check = 0;

void BackTrack(int i,int bd,int sum,int s){
    if(check) return;
    for(int j=bd;j<=n;j++){
        if(sum+a[j]<=s){
            if(sum+a[j]==s){
                check = 1;
                return ;
            }else{
                BackTrack(i+1,bd+1,sum+a[j],s);
            }
        }else{
            return;
        }
    }
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int s = accumulate(a+1,a+1+n,0);
    if(s%2==1){
        cout << 0;
        return 0;
    }
    BackTrack(1,1,0,s/2);
    if(check==1){
        cout << 1;
    }else{
        cout << 0;
    }
}