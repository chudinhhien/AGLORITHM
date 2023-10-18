#include<bits/stdc++.h>
using namespace std;

int n;
int x[10]={0};
bool used[10];

void in(){
    for(int i=1;i<=n;i++){
        cout << x[i];
    }
    cout << endl;
}

void BackTrack(int i){
    for(int j=1;j<=n;j++){
        if(!used[j]&&abs(j-x[i-1])!=1){
            x[i] = j;
            used[j] = true;
            if(i==n){
                in();
            }else{
                BackTrack(i+1);
            }
            used[j] = false;
        }
    }
}


int main(){
    cin >> n;
    x[0] = -1;
    BackTrack(1);    
}