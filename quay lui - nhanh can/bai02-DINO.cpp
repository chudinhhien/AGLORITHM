#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> c;
    queue<int> h;
    int n,tmp;
    cin >> n;
    int a[n+1];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=n-1;i>=0;i--){
        c.push(a[i]);
    }
    string s;cin >> s;
    for(char x:s){
        if(x=='C'){
            int tmp = c.top();
            c.pop();
            h.push(tmp);
        }else{
            c.push(h.front());
            h.pop();
        }
    }
    while(!c.empty()){
        cout << c.top() << ' ';
        c.pop();
    }
}
