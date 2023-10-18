#include<bits/stdc++.h>
using namespace std;

string s;
string tmp;

void Try(int i){
    tmp.push_back(toupper(s[i]));
    if(i==s.size()-1){
        cout << tmp << endl;
    }else Try(i+1);
    tmp.pop_back();

    tmp.push_back(tolower(s[i]));
    if(i==s.size()-1){
        cout << tmp << endl;
    }else Try(i+1);
    tmp.pop_back();
}

int main(){
    cin >> s;
    Try(0);
}