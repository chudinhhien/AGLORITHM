#include<bits/stdc++.h>
using namespace std;

bool check(string s){
    int l = 0, r = s.size()-1;
    while(l<r){
        if(s[l]!=s[r]) return false;
        ++l;--r;
    }
    return true;
}

vector<vector<string>> res;
vector<string> v;

void Try(int start,string s){
    if(start>=s.size()) res.push_back(v);
    for(int end = start;end<s.size();end++){
        if(check(s.substr(start,end-start+1))){
            v.push_back(s.substr(start,end-start+1));
            Try(end+1,s);
            v.pop_back();
        }
    }
}

int main(){
    string s;
    cin >> s;
    Try(0,s);
    for(auto it:res){
        for(string x:it) cout << x << ' ';
        cout << endl;
    }
}