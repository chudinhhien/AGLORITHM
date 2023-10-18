#include<bits/stdc++.h>
using namespace std;

int h,m,ss;
bool check(string s){
    if(s.length()!=8) return false;
    if(!isdigit(s[4])) return false;
    for(int i=0;i<s.length();i++){
        if(!isdigit(s[i])&&(s[i]!=':')){
            return false;
        }
    }
    h = stoi(s.substr(0,2));
    m = stoi(s.substr(3,5));
    ss = stoi(s.substr(6,8));
    if(h<0||h>23) return false;
    if(m<0||m>59) return false;
    if(ss<0||ss>59) return false;
    return true;
}

int main(){
    string s;
    getline(cin,s);
    if(!check(s)) cout << "INCORRECT";
    else cout << h*3600+m*60+ss;
    return 0;
}