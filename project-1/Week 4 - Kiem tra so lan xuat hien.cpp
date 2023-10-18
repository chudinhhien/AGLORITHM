#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    map<int,int> mp;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(mp[a[i]]) cout << "1\n";
        else cout << "0\n";
        mp[a[i]]=1;
    }
    return 0;
}