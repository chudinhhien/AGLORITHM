//C++ 
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;

int Mod = 1e9+7;


ll binaryPow(ll a,ll b){
    if(b==0) return 1;
    ll tmp = binaryPow(a,b/2);
    if(b%2==0){
        return (tmp%Mod)*(tmp%Mod)%Mod;
    }else{
        return ((tmp%Mod)*(tmp%Mod)%Mod)*(a%Mod)%Mod;
    }
}

int main() 
{ 
    ll a,b;
    cin >> a >> b;
    cout << binaryPow(a,b);
    return 0;
}
