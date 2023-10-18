//C++ 
#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

int mod = 1e9+7;
int k,n;
ll m[1005][1005];


ll C(int i,int j){
    if(i==0||i==j) m[i][j] = 1ll;
    else{
        if(m[i][j]<0){
            m[i][j] = C(i-1,j-1)%mod + C(i,j-1)%mod;
        }
    }
    return m[i][j]%mod;
}

int main() 
{ 
    cin >> k >> n;
    for(int i=0;i<=k;i++){
        for(int j=0;j<=n;j++){
            m[i][j] = -1;
        }
    }
    cout << C(k,n) << endl;
    return 0;
}
