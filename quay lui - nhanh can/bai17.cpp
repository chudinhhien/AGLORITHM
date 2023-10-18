#include<bits/stdc++.h>
using namespace std;

string s;
string tmp = "()[]{}";
int n;

bool check(string s){
    stack<char> st;
    for(char x:s){
        if(x=='('||x=='['||x=='{'){
            st.push(x);
        }else{
            if(st.empty()) return false;
            char y = st.top();
            st.pop();
            if((x==')'&&y!='(')||(x==']'&&y!='[')||(x=='}'&&y!='{')) return false;
        }
    }
    if(st.empty()) return true;
    return false;
}

void Try(int i){
    for(int j=0;j<6;j++){
        s+=tmp[j];
        if(i==n){
            if(check(s)){
                cout << s << ' ';
            }
        }else{
            Try(i+1);
        }
        s.pop_back();
    }
}

int main(){
    cin >> n;
    if(n%2==1) cout << "NOT FOUND\n";
    else Try(1);
}