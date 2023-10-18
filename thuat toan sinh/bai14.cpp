#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,final;
string s;

void ktao(){
    for(int i=1;i<=n;i++){
        s+="0";
    }
    s[n-1]='8';
}

void sinh(){
    int i = n-1;
    while(i>=0&&s[i]=='8'){
        s[i]='0';
        --i;
    }
    if(i==-1){
        final=1;
    }else{
        s[i]='8';
    }
}

int main(){
    n=19;
    vector<ll> v;
    ktao();
    while(!final){
        v.push_back(stoll(s));
        sinh();
    }
    ll ans[301];
    for(int i=1;i<=300;i++){
        for(ll x : v){
            if(x%i==0){
                ans[i]=x;
                break;
            }
        }
    }
    int t;cin >> t;
    while(t--){
        int x;cin >> x;
        cout << ans[x] << endl;
    }
}