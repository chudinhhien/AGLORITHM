#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin >> n >> q;
    int a[n];
    int cnt=0;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(2*a[i]>q) break;
        if(binary_search(a+i+1,a+n,q-a[i])){
            ++cnt;
        }
    }
    cout << cnt;
}