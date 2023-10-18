//CPP 
#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

int main() 
{
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int &x:a){
        cin >> x;
    }
    int tmp = 0,cnt=0;
    for(int i=0;i<k;i++) tmp+=a[i];
    if(tmp%2==0) ++cnt;
    for(int i=k;i<n;i++){
        tmp = tmp - a[i-k] + a[i];
        if(tmp%2==0) ++cnt;
    }
    cout << cnt;
    return 0;
}