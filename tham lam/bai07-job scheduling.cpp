#include<bits/stdc++.h>
using namespace std;

bool comparator(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second!=b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){
    vector<pair<int,int>> v;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        pair<int,int> tmp;
        cin >> a >> b;
        tmp.first=a;tmp.second=b;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),comparator);
    for(auto it:v){
        cout << '(' << it.first << ' ' << it.second << ')' << endl;
    }
}