#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,k;
    ll ans=0;
    cin >> n >> k;
    vector<int> v;
    for(int i=0;i<n;i++){
        int l,t;
        cin >> l >> t;
        if(t==0){
            ans+=l;
        }else{
            v.push_back(l);
        }
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<v.size();i++){
        if(i<k){
            ans+=v[i];
        }else ans -=v[i];
    }
    cout << ans << endl;
}