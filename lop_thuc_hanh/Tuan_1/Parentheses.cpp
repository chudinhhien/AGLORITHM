//C++ 
#include <bits/stdc++.h>
using namespace std;

bool check(string s){
    stack<char> st;
    for(char x:s){
        if(x=='('||x=='['||x=='{'){
            st.push(x);
        }else{
            if(st.empty()) return false;
            char c = st.top();
            st.pop();
            if((c=='('&&x!=')')||(c=='['&&x!=']')||(c=='{'&&x!='}')) return false;
        }
    }
    if(!st.empty()) return false;
    return true;
}

int main() 
{ 
    string s;
    cin >> s;
    if(check(s)) cout << '1';
    else cout << '0';
    return 0;
}