#include <bits/stdc++.h>
using namespace std;

int n, m, ans, moneyToWalk;
vector <int> money;

int main(){
  while(1){
    cin >> n >> m;
    if(!n && !m) break;
    ans = 0;
    moneyToWalk = m / n;
    money.resize(n);
    for(int i = 0; i < n; i++) cin >> money[i];
    for(auto p : money){
      if(moneyToWalk > p) ans += p;
      else ans += moneyToWalk;
    }
    cout << ans << '\n';
  }
}