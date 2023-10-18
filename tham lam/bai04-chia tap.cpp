#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,k;
    cin >> n >> k;
    int a[n];
    k = min(n,n-k);
    ll s1 = 0, s2=0;
    for(int &x:a) cin >> x;
    sort(a,a+n);
    for(int i=0;i<k;i++){
        if(i<k) s1+=a[i];
        else s2+=a[i];
    }
    cout << s2-s1;
}