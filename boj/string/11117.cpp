#include <bits/stdc++.h>
using namespace std;
int cookieNum, testCase, alpha[26], alphaCopy[26];
string cookieWord, let;
int main(){
    cin >> testCase;

    while(testCase--){
        memset(alpha,0,sizeof(alpha));
        cin >> cookieWord;

        for(int i = 0; i < cookieWord.size(); i++) alpha[cookieWord[i]-'A']++;
        cin >> cookieNum;

        for(int i = 0; i < cookieNum; i++){
            for(int i = 0; i < 26; i++) alphaCopy[i] = alpha[i];
            cin >> let;
            
            int f = 0;

            for(int j = 0; j < let.size(); j++){
                if(!alphaCopy[let[j]-'A']) f = 1;
                else alphaCopy[let[j]-'A']--;
            }

            if(!f) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}