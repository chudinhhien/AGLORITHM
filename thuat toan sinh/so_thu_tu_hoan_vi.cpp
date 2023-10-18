#include<bits/stdc++.h>
using namespace std;
int n;
bool check(int x[],int s[]){
    for(int i=1;i<=n;i++){
        if(x[i]!=s[i]) return 0;
    }
    return 1;
}
int main(){
    int x[100],s[100],cnt=1;
    cin >> n;
    for(int i = 1;i<=n;i++){
        s[i]=i;
        cin >> x[i];
    }
    do{
        if(check(x,s)){
            cout << cnt;
            return 0;
        }
        ++cnt;
    }while(next_permutation(s+1,s+n+1));
}