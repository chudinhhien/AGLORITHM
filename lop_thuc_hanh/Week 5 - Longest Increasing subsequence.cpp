#include<bits/stdc++.h>
using namespace std;

int main() 
{ 
    int n;
    cin >> n;
    int a[n+1];
    int S[n+1]={0};
    for(int i=1;i<=n;i++) cin >> a[i];
    S[1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(a[i]>a[j]){
                if(S[j]+1>S[i]){
                    S[i] = S[j] + 1;
                }
            }
        }
        S[i] = max(1,S[i]);
    }
    int ans = -1;
    for(int i=1;i<=n;i++){
        ans = max(ans,S[i]);
    }
    cout << ans;
    return 0;
}
