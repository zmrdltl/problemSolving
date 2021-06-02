#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main(){
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> s;
        cout << "String #" << i << '\n';
        for(int i = 0; i < s.size(); i++) {
            printf("%c",((s[i] - 'A') + 1) % 26  + 'A');
        }
        cout << '\n';
        cout << '\n';
    }
}