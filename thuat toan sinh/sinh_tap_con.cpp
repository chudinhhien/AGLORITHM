#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[]={1,2,3};
    int n=3;
    for(int i=0;i<=(1<<n);i++){//duyet tat ca tu 0 den 2^N
        for(int j = 0;j<n;j++){
            if(i&(1<<j)){
                cout << a[j] << ' ';
            }
        }
        cout << endl;
    }
}