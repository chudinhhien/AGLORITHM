//CPP 
#include <bits/stdc++.h>
using namespace std; 



int main() 
{
    freopen("text.txt","r",stdin); 
    char word[100];int n=0;
    bool startWord = true;
    wchar_t t = L'—';
    while(!feof(stdin)){
        char c = fgetc(stdin);
        if(startWord&&(isalpha(c)||c=='-')){
            ++n;
            startWord = false;
        }
        else if(!startWord&&(!isalpha(c)&&c!='-')){
            startWord = true;
        }
    }
    cout << n;
    return 0;
}