#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int t, x, w, ans;

int main(){
  fastio;
  cin >> t;
  while(t--){
    ans = 0;
    cin >> x >> w;
    while(x < w){
      x *= 2;
      ans++;
    }
    cout << ans << '\n';
  }
}