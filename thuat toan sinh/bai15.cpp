#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    string s;
    cin >> s;
    string res="";
    int cnt[256]={0};
    for(char x:s){
        if(cnt[x]==0){
            res+=x;
        }
        cnt[x]=1;
    }
    sort(res.begin(),res.end());
    do{
        cout << res << endl;
    }while(next_permutation(res.begin(),res.end()));
}