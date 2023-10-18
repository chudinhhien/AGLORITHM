#include<bits/stdc++.h>
using namespace std;

int n,m;
char a[10][10];
int visited[10][10];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int check = 0;
string tmp;
string s;

void Try(int i,int j){
    cout << tmp << endl;
    if(check) return;
    if(tmp==s){
        check = 1;
        return;
    }
    for(int k=0;k<4;k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1>=0&&i1<n&&j1>=0&&j1<m&&visited[i1][j1]==0){
            tmp+=a[i1][j1];
            visited[i1][j1]=1;
            if(tmp==s){
                check = 1;
            }else if(s.find(tmp)!=string::npos){
                Try(i1,j1);
            }
            tmp.pop_back();
            visited[i1][j1]=0;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    cin >> s;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==s[0]){
                memset(visited,0,sizeof(visited));
                tmp = "";
                tmp+=a[i][j];
                visited[i][j] = 1;
                Try(i,j);
                if(check){
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    } 
    cout << "NO";
}