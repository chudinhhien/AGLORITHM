#include<bits/stdc++.h>
using namespace std;

int main() 
{ 
    //freopen("text.txt","r",stdin);

   
    int c;
    while ((c = fgetc(stdin)) != EOF) {
        if (isalpha(c)) {
            c = toupper(c);
        }
        cout << (char)c;
    }
    return 0;
}
