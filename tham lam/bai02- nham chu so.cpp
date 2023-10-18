#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll xuly(ll n, char p, char q){
    string s = to_string(n);
    for(int i=0;i<s.length();i++){
        if(s[i]==p) s[i] = q;
    }
    return stoll(s);
}

int main(){
    ll a,b;
    cin >> a >> b;
    cout << xuly(a,'5','6') + xuly(a,'6','5') << endl;
    cout << xuly(a,'6','5') + xuly(a,'5','6') << endl;
}