#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    int a[n];
    priority_queue<int, vector<int>,greater<int>> pq;
    for(int &x:a){
        cin >> x;
        pq.push(x);
    }
    ll ans = 0;
    while(pq.size()>=2){
        int t1 = pq.top();pq.pop();
        int t2 = pq.top();pq.pop();
        ans+=(t1+t2);
        pq.push(t1+t2);
    }
    cout << ans;
    return 0;
}