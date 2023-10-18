#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;

    // Precompute powers of 256 modulo m
    vector<ll> powers;
    powers.push_back(1);
    for (int i = 1; i <= 300; i++) {  // Choose a sufficiently large value
        powers.push_back((powers.back() * 256) % m);
    }

    while (n--) {
        ll Result = 0;
        string s;
        cin >> s;
        int k = s.length();
        s = "0" + s;
        
        for (int i = 1; i <= k; i++) {
            Result += 1ll * (s[i] % m) * powers[k - i];
            Result %= m;
        }
        
        cout << Result << endl;
    }
    
    return 0;
}
