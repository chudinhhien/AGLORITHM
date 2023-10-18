#include<bits/stdc++.h>
using namespace std;

bool check(int a[],int b[],int n){
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]&&a[-i-1]!=b[i]) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b,b+n);
    if(check(a,b,n)) cout << "YES";
    else cout << "NO";
}