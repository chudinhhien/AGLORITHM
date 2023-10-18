#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[10] = {1,2,5,10,20,50,100,200,500,1000};
    int ans = 0;
    for(int i=9;i>=0;i--){
        if(i==0){
            ans+=n;
        }else{
            if(n>=a[i]){
                ans+=n/a[i];
                n = n % a[i];
            }
        }
    }
    cout << ans;
}