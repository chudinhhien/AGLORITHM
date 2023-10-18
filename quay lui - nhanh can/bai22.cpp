#include<bits/stdc++.h>
using namespace std;

int n,k;
int x[10];
int check = 0;
vector<vector<int>> res;
vector<int> tmp;

void in(){
    for(int j=1;j<=k;j++){
        if(j<k){
            cout << x[j] << '+';
        }else{
            cout << x[j] << endl;
        }
    }
}

void Try(int i,int s){
    for(int j=i;j<=9;j++){
        tmp.push_back(j);
        s+=j;
        if(s==n&&tmp.size()==k){
            res.push_back(tmp);
        }else if(s<n&&tmp.size()<k){
            Try(j+1,s);
        }
        tmp.pop_back();
        s-=j;
    }
}

int main(){
    cin >> n >> k;
    Try(1,0);
    if(res.size()==0){
        cout << "NOT FOUND";
    }else{
        sort(res.begin(),res.end());
        for(auto tmp:res){
            for(int j=0;j<tmp.size();j++){
                cout << tmp[j];
                if(j!=tmp.size()-1) cout << ' + ';
            }
            cout << endl;
        }
    }
}