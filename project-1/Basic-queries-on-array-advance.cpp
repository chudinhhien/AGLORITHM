#include<bits/stdc++.h>
using namespace std;


int n;
int f[18][100005];
int min_array = 1001 , sum = 0;

void Make_ST(){
    for(int i=1;i<=log2(n);i++){
        for(int u=1;u<=(n-(1<<i)+1);u++){
            f[i][u] = max(f[i-1][u],f[i-1][u+(1<<(i-1))]);
        }
    }
}

int findMax(int l,int r){
    int k = log2(r-l+1);
    return max(f[k][l],f[k][r-(1<<k)+1]);
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> f[0][i];
        min_array = min(min_array,f[0][i]);
        sum+=f[0][i];
    }
    Make_ST();
    char c ;
    cin >> c;
    while(true){
        string s;
        cin >> s;
        if(s=="***") break;
        if(s=="find-max"){
            cout << findMax(1,n) << endl;
        }else if(s=="find-min"){
            cout << min_array << endl;
        }else if(s=="find-max-segment"){
            int l,r;
            cin >> l >> r;
            cout << findMax(l,r) << endl;
        }else if(s=="sum"){
            cout << sum << endl;
        }
    }
    return 0;
}