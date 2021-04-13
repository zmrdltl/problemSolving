#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(1){
        int alpha[26] = {0}, ans = 0;
        getline(cin,s);
        if(s=="#") break;
        for(int i = 0; i < s.size(); i++){
            if('A' <= s[i] && s[i] <= 'Z') {
                s[i] = s[i] - 'A' + 'a';
            }
        }
        for(int i = 0; i < s.size(); i++){
            if('a' <= s[i] && s[i] <= 'z'){
                alpha[s[i]-'a'] = 1;
            }
        }
        for(int i = 0; i < 26; i++) if(alpha[i])ans++;
        cout << ans << '\n';
    }
}