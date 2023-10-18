//CPP 
#include <bits/stdc++.h> 
using namespace std;

int main() 
{ 
    queue<int> q;
    string s;
    while(true){
        cin >> s;
        if(s=="#") break;
        if(s=="PUSH"){
            int n;
            cin >> n;
            q.push(n);
        }else if(s=="POP"){
            if(q.empty()){
                cout << "NULL" << endl;
            }else{
                cout << q.front() << endl;
                q.pop();
            }
        }
    }
}