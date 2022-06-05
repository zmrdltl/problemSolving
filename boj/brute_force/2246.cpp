#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n, ans, can, xd, xc, d, c;
vector <pii> v;

int main(){
  cin >> n;
  v.resize(n);
  for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

  for(int i = 0; i < n; i++){
    can = 1;
    xd = v[i].first;
    xc = v[i].second;
    for(int j = 0; j < n; j++){
      if(i == j) continue;
      d = v[j].first;
      c = v[j].second;
      if(xd >= d && xc >= c) { can = 0; break; }
      if(xc >= c && xd >= d) { can = 0; break; }
    }
    if(can) ans++;
  }

  cout << ans;
}