#include<bits/stdc++.h>

using namespace std;

int n,final=0;
int a[100];
vector<vector<int>> res;
void ktao(){
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
}
void sinh(){
    int i = n-1;
    while(i>=1&&a[i]>a[i+1]){// vi tri dau tien a[i]<a[i+1]
        --i;
    }
    if(i==0){
        final = 1;
    }else{
        int j = n;
        while(a[i]>a[j]) --j;
        swap(a[i],a[j]);
        reverse(a+i+1,a+n+1);
    }
}

int main(){
    cin >> n;
    ktao();
    while(!final){
        vector<int> tmp(a+1,a+n+1);
        res.push_back(tmp);
        sinh();
    }
    for(int i=0;i<res.size();i++){
        for(int x:res[i]){
            cout << x << ' ';
        }
        cout << endl;
    }
}

//next_permutation: tim cau hinh sau cua hoan vi
//pre_permutation: tim cau hinh truoc cua hoan vi