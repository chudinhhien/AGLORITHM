#include<bits/stdc++.h>
using namespace std;

int n,a[100],final=0,cnt;
void ktao(){
    cnt = 1;
    a[1]= n;
}
void sinh(){
    // bat dau tu so hang cuoi cung va tim so hang dau tien khac 1
    int i = cnt;
    while(i>=1&&a[i]==1){
        --i;
    }
    if(i==0){
        final=1;
    }else{
        a[i]--;
        int d = cnt - i + 1;
        cnt=i;
        int q = d/a[i];
        int r = d%a[i];
        for(int j=1;j<=q;j++){
            a[i+j]=a[i];
            ++cnt;
        }
        if(r!=0){
            ++cnt;
            a[cnt]=r;
        }
    }
}

int main(){
    cin >> n;
    ktao();
    while(!final){
        for(int i=1;i<=cnt;i++){
            cout << a[i] << ' ';
        }
        cout << endl;
        sinh();
    }
}