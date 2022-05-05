#include <bits/stdc++.h>
using namespace std;
string s, t;
int main(){
  while(cin >> s >> t){
    int piv = 0;
    string tmp;
    for(int i = 0; i < t.size(); i++){
      if(piv < s.size() && t[i] == s[piv]) tmp += t[i], piv++;
    }
    if(tmp == s) cout << "Yes\n";
    else cout << "No\n";
  }
}