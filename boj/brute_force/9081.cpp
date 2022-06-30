#include <bits/stdc++.h>
using namespace std;
int t, cnt;
string s, ans;

int main(){
    cin >> t;
    while(t--){
        cin >> s;
        cnt = 0;
        do{
            ans = s;
            if(++cnt == 2) break;
        }while(next_permutation(s.begin(), s.end()));
        cout << ans << '\n';
    }
}