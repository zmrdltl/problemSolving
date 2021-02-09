#include <bits/stdc++.h>
using namespace std;
int big;
int alpha[26];
int main() {
    while (1) {
        char c = 0;
        cin >> c;
        if (c == 0) break;
        if ('a' <= c && c <= 'z') alpha[c - 'a']++; 
    }
    for (int i = 0; i < 26; i++)
        if (big < alpha[i]) 
            big = alpha[i];

    for(int i = 0; i < 26; i++)
        if(alpha[i]==big) 
            printf("%c",i + 'a');
}