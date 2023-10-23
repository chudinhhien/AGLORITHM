//C++ 
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
    int n;
    cin >> n;
    int a[n+1];
    int S[n+1]; //gọi S[i] là tổng dãy con liên tiếp kết thúc tại a[i]
    for(int i=1;i<=n;i++) cin >> a[i];
    S[1] = a[1];
    for(int i=2;i<=n;i++){
        if(S[i-1]>0){
            S[i] = S[i-1]+a[i];
        }else{
            S[i] = a[i];
        }
    }
    int ans = -1e9;
    for(int i=1;i<=n;i++){
        ans = max(ans,S[i]);
    }
    cout << ans;
    return 0;
}