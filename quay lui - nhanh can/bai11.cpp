#include<bits/stdc++.h>
using namespace std;

int a[21];
int x[21];
int n;
vector<string> v;
void BackTrack(int i,int bd){
    for(int j=bd;j<=n;j++){
        if(a[j]>x[i-1]){
            x[i] = a[j];
            if(i>=2){
                string s = "";
                for(int u=1;u<=i;u++){
                    s+=to_string(x[u]);
                }
                v.push_back(s);
            }
            BackTrack(i+1,j+1);
        }
    }
} 

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    x[0]=0;
    BackTrack(1,1);
    sort(v.begin(),v.end());
    for(string s:v){
        for(char c:s){
            cout << c << " ";
        }
        cout << endl;
    }
}