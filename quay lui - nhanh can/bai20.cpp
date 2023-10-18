#include<bits/stdc++.h>
using namespace std;

string s;
string ans;
int n,k;

void Try(int i){
    for(int j=0;j<n;j++){
        ans+=s[j];
        if(ans.size()==k){
            cout << ans << endl;
        }else{
            Try(j);
        }
        ans.pop_back();
    }
}

int main(){
    cin >> n >> k >> s;
    sort(s.begin(),s.end());
    Try(0);
}