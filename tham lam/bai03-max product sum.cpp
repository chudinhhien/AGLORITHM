#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int mod = 1e9+7;
    int n;
    int a[n+1];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    long long ans = 0;
    for(int i=0;i<n;i++){
        ans+=1ll*a[i]*i;
        ans%=mod;
    }
    cout << ans;
}