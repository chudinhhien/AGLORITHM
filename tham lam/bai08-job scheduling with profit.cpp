#include<bits/stdc++.h>
using namespace std;

struct job{
    int id, deadline, profit;
}

int main(){
    int n;
    cin >> n;
    vector<job> v;
    for(int i=0;i<n;i++){
        job x;
        cin >> x.id >> x.deadline >> x.profit;
        v.push_back(x);
    }
    
}