#include <bits/stdc++.h>
using namespace std;
int main(){
    for(int i = 0; i < 3; i++){
        string s;
        cin >> s;
        int ans = 0;
        for(int j = 0; j < s.size(); j++){
            int cnt = 0;
            while(s[j]==s[j+1])
                cnt++, j++;
            ans = max(ans,cnt + 1);
        }
        cout << ans << '\n';
    }
}