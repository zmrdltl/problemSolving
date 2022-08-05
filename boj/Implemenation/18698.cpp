#include <bits/stdc++.h>
using namespace std;
int t, ans;
string s;
int main(){
  cin >> t;
  while(t--){
    ans = 0;
    cin >> s;
    for(auto c : s){
      if(c == 'D') break;
      ans++;
    }
    cout << ans << '\n';
  }
}