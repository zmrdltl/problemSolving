#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int t;
string n;
int main(){
    fastio;
    cin >> t;
    while(t--){
        cin >> n;
        int ans = 0;
        while(n != "6174"){
            vector<char> s;
            for(int i = 0; i < n.size(); i++) s.push_back(n[i]);
            string big="",small="";
            sort(s.rbegin(),s.rend());
            for(auto a : s) big += a;
            sort(s.begin(),s.end());
            for(auto a : s) small += a;
            ans++;
            cout << "BIG, small : " << big << ' ' << small << '\n';
            n = to_string(stoi(big) - stoi(small));
        }
        cout << ans << '\n';
    }
}