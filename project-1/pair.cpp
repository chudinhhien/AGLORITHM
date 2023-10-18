//C++ 
#include <bits/stdc++.h> 
using namespace std;

int main() 
{ 
    int n,m;
    cin >> n >> m;
    int a[n];
    int q = 0;
    for(int &x:a) cin >> x;
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(binary_search(a+i+1,a+n,m-a[i])) ++q; 
    }
    cout << q;
    return 0;
}