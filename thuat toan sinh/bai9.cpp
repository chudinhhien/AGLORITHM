#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n,k,final=0;
vector<string> res;
string s;

void ktao(){
    for(int i=1;i<=n;i++){
        s+="0";
    }
}

void sinh(){
    int i = n-1;
    while(i>=0&&s[i]=='1'){
        s[i]='0';
        --i;
    }
    if(i==-1){
        final=1;
    }else{
        s[i]='1';
    }
}

bool check1(string s){
    int dem = 0;
    for(char c:s){
        if(c=='1') ++dem;
    }
    return dem==k;
}
bool check2(string s){
    int ans = 0;
    int dem = 0;
    for(char c:s){
        if(c=='1'){
            ++dem;
            if(dem>k) return false;
        }else{
            if(dem==k) ++ans;
            dem = 0;
        }
    }
    if(dem==k) ++ans;
    return ans == 1;
}
int main(){
    cin >> n >> k;
    ktao();
    while(!final){
        res.push_back(s);
        sinh();
    }
    for(string x:res){
        if(check1(x)) cout << x << ' ';
    }
    cout << endl;
    for(string x:res){
        if(check2(x)) cout << x << ' ';
    }
}