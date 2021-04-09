#include <bits/stdc++.h>
using namespace std;
int t,a,b;
string s;

char E(char X){
    return (a * (X -'A') + b) % 26 + 'A';
}
int main(){
    cin >> t;
    while(t--){
        cin >> a >> b;
        cin >> s;
        string ans = "";
        for(int i = 0; i < s.size(); i++) ans += E(s[i]);
        cout << ans << '\n';
    }
}