#include<bits/stdc++.h>
using namespace std;

int n,x[15],ok=0;
string s[15];
void ktao(){
    for(int i=1;i<=n;i++){
        x[i]=i;
    }
}
void sinh(){
    int i = n-1;
    while(i>=1&&x[i]>x[i+1]) --i;
    if(i==0){
        ok=1;
    }else{
        int j = n;
        while(x[i]>x[j]) --j;
        swap(x[i],x[j]);
        reverse(x+i+1,x+n+1);
    }
}
int main(){
    cin >> n;
    ktao();
    for(int i=1;i<=n;i++){
        cin >> s[i];
    }
    sort(s+1,s+n+1);
    while(!ok){
        for(int i=1;i<=n;i++){
            cout << s[x[i]] << ' ';
        }
        cout << endl;
        sinh();
    }
}