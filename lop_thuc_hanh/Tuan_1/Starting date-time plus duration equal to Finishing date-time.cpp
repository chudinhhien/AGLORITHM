//C++ 
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
    set<string> st;
    string s;
    while(true){
        cin >> s;
        if(s=="*") break;
        st.insert(s);
    }
    string dd,tt;
    int ss;
    while(true){
        cin >> dd;
        if(dd=="***") break;
        cin >> tt >> ss;
        int t = stoi(tt.substr(0,2))*3600+stoi(tt.substr(3,5))*60+stoi(tt.substr(6,8));
        t = t + ss;
        if(t>86400){
            int m;
            m = t/86400;
            t = t%86400;
            string tmp = dd;
            while(m--){
                auto it = st.upper_bound(tmp);
                tmp = (*it);
            }
            int hh,mm,sss;
            hh = t/3600;
            t = t%3600;
            mm = t/60;
            sss = t%60;
            cout << tmp << ' ';
            printf("%02d:%02d:%02d\n",hh,mm,sss); 
        }else{
            int hh,mm,sss;
            hh = t/3600;
            t = t%3600;
            mm = t/60;
            sss = t%60;
            cout << dd << ' ';
            printf("%02d:%02d:%02d\n",hh,mm,sss);
        }
    }
    return 0;   
}