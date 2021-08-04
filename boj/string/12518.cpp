#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int testCase, cnt;
int main(){
    fastio;
    cin >> testCase;
    for(cnt = 1; cnt <= testCase; cnt++){
        char s[101], lastChar, k[10];
        cin >> s;

        lastChar = s[strlen(s)-1];
        if(lastChar == 'y' || lastChar == 'Y') strcpy(k,"nobody");

        else if(
            lastChar == 'a' || 
            lastChar == 'e' || 
            lastChar == 'i' || 
            lastChar == 'o' || 
            lastChar == 'u' ||
            lastChar == 'A' || 
            lastChar == 'E' || 
            lastChar == 'I' || 
            lastChar == 'O' || 
            lastChar == 'U'
        ) strcpy(k,"a queen");

        else strcpy(k,"a king");
        
        printf("Case #%d: %s is ruled by %s.\n", cnt, s, k);
    }
}