#include<bits/stdc++.h>
using namespace std;

int n,k;
int x[100];
vector<int> prime;
vector<int> tmp;
vector<vector<int>> res;

bool nt(int i){
    for(int j=2;j<=sqrt(i);j++){
        if(i%j==0) return false;
    }
    return i>1;
}

void Try(int idx,int sum){
    for(int j=idx;j<prime.size();j++){
        tmp.push_back(prime[j]);
        sum+=prime[j];
        if(sum==n&&tmp.size()==k){
            res.push_back(tmp);
        }else if(sum<n&&tmp.size()<k){
            Try(j+1,sum);
        }
        tmp.pop_back();
        sum-=prime[j];
    }
}

int main(){
    cin >> n >> k;
    for(int i=1;i<=500;i++){
        if(nt(i)) prime.push_back(i);
    }
    Try(0,0);
    if(res.size()==0){
        cout << "NOT FOUND";
    }else{
        for(auto tmp:res){
            for(int i=0;i<tmp.size();i++){
                cout << tmp[i];
                if(i!=tmp.size()-1) cout << " + ";
            }
            cout << endl;
        }
    }
}