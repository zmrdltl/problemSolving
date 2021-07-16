#include <bits/stdc++.h>
using namespace std;
string s, t;
int ans, d[4001][4001];
int main(){
    cin >> s >> t;
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < t.size(); j++){
            if(s[i] == t[j]){
                d[i+1][j+1] = d[i][j] + 1;
                ans = max(ans,d[i+1][j+1]);
            }
        }
    }
    cout << ans << '\n';
}