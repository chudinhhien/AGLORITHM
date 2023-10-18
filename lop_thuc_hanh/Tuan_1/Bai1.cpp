//C++ 
#include <bits/stdc++.h>
using namespace std;

bool check(string s){
    for(char x:s){
        if(!isdigit(x)) return false;
    }
    return true;
}

int main() 
{ 
    int n;
    int m = 1;
    int sum = 0;
    map<string, int> mp;
    map<string, long long> time_tel;
    
    string s;
    while(true){
        cin >> s;
        if(s=="#") break;
        string from_number,to_number,date,from_time,end_time;
        cin >> from_number >> to_number >> date >> from_time >> end_time;
        if(check(from_number)&&check(to_number)){
            mp[from_number]++;
            sum++;
            long long time_from = 0, time_end = 0;
            time_from=3600*stoll(from_time.substr(0,2))+60*stoll(from_time.substr(3,5))+stoll(from_time.substr(6,8));
            time_end=3600*stoll(end_time.substr(0,2))+60*stoll(end_time.substr(3,5))+stoll(end_time.substr(6,8));
            time_tel[from_number]+=time_end - time_from;
        }else{
            m = 0;
        }
    }
    while(true){
        cin >> s;
        if(s=="#") break;
        if(s=="?check_phone_number") cout << m << endl;
        else if(s=="?number_calls_from"){
            string x;
            cin >> x;
            cout << mp[x] << endl;
        }else if(s=="?number_total_calls"){
            cout << sum << endl;
        }else if(s=="?count_time_calls_from"){
            string x;
            cin >> x;
            cout << time_tel[x] << endl;
        }
    }
    return 0;
}