#include <bits/stdc++.h>
using namespace std;
int thickness;
string s, ans;
int main(){
  cin >> thickness >> s;
  for(int i = 0; i < s.size(); i+=thickness){
    ans += s[i];
  }
  cout << ans;
}