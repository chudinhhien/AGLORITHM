#include<bits/stdc++.h>
using namespace std;


int y,d,m;
bool check(string s){
    if(s.length()!=10) return false;
    if(!isdigit(s[6])) return false;
    for(int i=0;i<s.length();i++){
        if(!isdigit(s[i])&&(s[i]!='-')) return false;
    }
    y = stoi(s.substr(0,4));
    m = stoi(s.substr(5,7));
    d = stoi(s.substr(8,10));
    if(m<1||m>12) return false;
    if(d<1||d>45) return false;
    return true;
}

int main(){
    string s;
    getline(cin,s);
    if(check(s)){
        cout << y << ' ' << m << ' ' << d;
    }else{
        cout << "INCORRECT";
    }
    return 0;
}