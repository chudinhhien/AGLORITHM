//CPP 
#include <bits/stdc++.h> 
using namespace std;

int main() 
{ 
    stack<int> st;
    string s;
    while(true){
        cin >> s;
        if(s=="#") break;
        if(s=="PUSH"){
            int n;
            cin >> n;
            st.push(n);
        }else if(s=="POP"){
            if(st.empty()){
                cout << "NULL" << endl;
            }else{
                cout << st.top() << endl;
                st.pop();
            }
        }
    }
}