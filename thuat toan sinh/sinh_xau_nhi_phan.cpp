#include<bits/stdc++.h>
using namespace std;

int n,a[100],final=0;

void ktao(){
    for(int i=1;i<=n;i++){
        a[i]=0;
    }
}

void sinh(){
    int i = n;// bat dau tu bit cuoi cung
    while(i>=1 && a[i]==1){   // duyet tu phai qua trai gap bit 1 thi chuyen thanh 0
        a[i]=0;               // gap bit 0 chuyen thanh 1 va dung
        --i;
    }
    if(i == 0){
        final = 1;   //day la cau hinh cuoi cung
    }else{
        a[i]=1;
    }
}
int main(){
    cin >> n;
    ktao();
    while(!final){
        for(int i=1;i<=n;i++){
            if(a[i]==0) cout << "B";
            else cout << "A";
        }
        cout << endl;
        sinh();
    }
}