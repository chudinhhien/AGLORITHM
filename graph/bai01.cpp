#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> ke[1005];
    int n,t;
    cin >> n >> t;
    while(t--){
        int i,j;
        cin >> i >> j;
        ke[i].push_back(j);
        ke[j].push_back(i);
    }
    for(int i=1;i<=n;i++){
        cout << i << " : ";
        sort(ke[i].begin(),ke[i].end());
        for(auto it:ke[i]){
            cout << (it) << ' ';
        }
        cout << '\n';
    }
}