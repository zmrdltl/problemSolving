#include <bits/stdc++.h>
using namespace std;
int n;
map <string,int> m;
string s;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        m[s]++;
    }
    string ans;
    for(int i = 0; i < n - 1; i++){
        cin >> s;
        m[s]--;
    }
    for(auto el : m) if(el.second != 0) ans = el.first;
    cout << ans << '\n';
}