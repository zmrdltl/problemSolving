#include <bits/stdc++.h>
using namespace std;
char s[30];
int testCase, cnt;
int main(){
    cin >> testCase;
    while(cin >> s){
        cnt++;

        char lastChar, k[10];
        lastChar = s[strlen(s)-1];
        if(lastChar == 'y') strcpy(k,"nobody");

        else if(
            lastChar == 'a' || 
            lastChar == 'e' || 
            lastChar == 'i' || 
            lastChar == 'o' || 
            lastChar == 'u'
        ) strcpy(k,"a queen");

        else strcpy(k,"a king");
        printf("Case #%d: %s is ruled by %s.\n", cnt, s, k);
    }
}