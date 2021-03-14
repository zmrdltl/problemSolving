#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int size = s.size();
        vector <char> password(size); 
        int cursor = 0;
        for(int i = 0; i < size; i++){
            password[i] = s[i];
        }
        for(int i = 0; i < size; i++){
            if(s[i] == '<'){
                cursor--;
                if(cursor < 0) cursor = 0;
            }else if(s[i] == '>'){
                cursor++;
                if(cursor>=size) cursor = size - 1;
            }else if(s[i] == '-'){
                password[cursor] = '0';
            }else cursor++;
        }
        for(int i = 0; i < size; i++){
            if(password[i]!='0' && password[i]!='-'
                && password[i]!='<' && password[i]!='>'
            ) cout << password[i];
        }
        cout << '\n';
    }
}