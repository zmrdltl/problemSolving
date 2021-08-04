#include <bits/stdc++.h>
using namespace std;
string s;
int alpha[26], cnt, ans;
vector <int> v;
int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++) alpha[s[i]-'a']++;
    for(int i = 0; i < 26; i++) if(alpha[i]) v.push_back(alpha[i]),cnt++;
    sort(v.begin(), v.end());

    for(int i = 0; i < cnt - 2; i++){
        ans += v[i];
    }
    cout << ans;
}