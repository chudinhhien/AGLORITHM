//CPP 
#include <bits/stdc++.h> 
using namespace std;


int main() 
{ 
    int n;
    cin >> n;
    int a[n+1];
    
    int min_array = 1001;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum+=a[i];
        min_array = min(min_array,a[i]);
    }
    char c; cin >> c;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            
        }
    }
    while(true){
        string s;
        cin >> s;
        if(s=="***") break;
        if(s=="find-max") cout << query[1][n] << endl;
        else if(s=="find-min") cout << min_array << endl;
        else if(s=="find-max-segment"){
            int i,j;
            cin >> i >> j;
            cout << query[i][j] << endl;
        }else if(s=="sum"){
            cout << sum << endl;
        }
    }
    return 0;
}