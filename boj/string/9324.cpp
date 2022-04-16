#include <bits/stdc++.h>
using namespace std;
int t;
string s, a;
int main(){
    cin >> t;
    while(t--){
        cin >> s;
        a = "";
        vector <int> ck(26,0);
        for(int i = 0; i < s.size(); i++){
            ck[s[i]-'A']++;
            a += s[i];
            if(ck[s[i]-'A'] == 3){
                a += s[i];
                ck[s[i]-'A'] = 0;
                i++;
            }
        }

        if(a == s) cout << "OK\n";
        else cout << "FAKE\n";
    }
}