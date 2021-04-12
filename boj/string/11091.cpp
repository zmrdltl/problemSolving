#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    cin.ignore();
    while(n--){
        string s;
        getline(cin,s);
        int alpha[26]={0};
        for(int i = 0; i < s.size(); i++){
            if('A'<=s[i]&&s[i]<='Z') s[i] = s[i] -'A' + 'a';
        }
        for(int i = 0; i < s.size(); i++){
            if('a'<=s[i]&&s[i]<='z') alpha[s[i]-'a'] = 1;
        }
        int flag = 0;
        for(int i = 0; i < 26; i++){
            if(!alpha[i] ){
                flag = 1;
                break;
            }
        }
        if(!flag) cout << "pangram\n";
        else {
            cout << "missing ";
            for(int i = 0; i < 26; i++){
                if(!alpha[i]){
                    cout << char('a' + i);
                }
            }
            cout << '\n';
        }
    }
}