#include<bits/stdc++.h>
using namespace std;

int final = 0;
int a[15];
int n;
void ktao(){
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
}

void sinh(){
    int i = n-1;
    while(i>=1&&a[i]>a[i+1]){
        --i;
    }
    if(i==0){
        final=1;
    }else{
        int j = n;
        while(a[j]<a[i]) --j;
        swap(a[i],a[j]);
        reverse(a+i+1,a+n+1);
    }
}


void in(){
    for(int i=1;i<=n;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}
int main(){
    cin >> n;
    ktao();
    while(!final){
       in();
       sinh();
    }
    return 0;
}