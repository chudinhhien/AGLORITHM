#include<bits/stdc++.h>
using namespace std;

int a[15];
int n,k,res=0;
int final=0;
void ktao(){
    for(int i=1;i<=n;i++){
        a[i]=0;
    }
}

void sinh(){
    int i = n;
    while(i>=1&&a[i]!=0){
        a[i]=0;
        --i;
        --res;
    }
    if(i==0){
        final=1;
    }else{
        a[i]=1;
        ++res;
    }
}

void in(){
    for(int i=1;i<=n;i++) cout << a[i];
    cout << endl;
}
int main(){
    cin >> n >> k;
    ktao();
    while(!final){
        if(res==k){
            in();
        }
        sinh();
    }
}