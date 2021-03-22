#include <bits/stdc++.h>
using namespace std;
string s, ans;

int alpha[26];

bool canNotMakePalin(){
    int cnt = 0;
    for(int i = 0; i < 26; i++)
        if(alpha[i] % 2 == 1) 
            cnt++;
    return cnt > 1;
}

int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++) alpha[s[i]-'A']++;
    
    if(canNotMakePalin()) {cout << "I'm Sorry Hansoo"; return 0;}

    for(int i = 0; i < 26; i++)
        for(int j = 0; j < alpha[i]/2; j++)
            ans += i + 'A';

    for(int i = 0; i < 26; i++)
        if(alpha[i]%2) 
            ans += i + 'A';

    for(int i = 25; i >= 0; i--)
        for(int j = 0; j < alpha[i]/2; j++)
            ans += i + 'A';

    cout << ans <<'\n';
}