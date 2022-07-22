#include <bits/stdc++.h>
using namespace std;
int t, a, b, ans = 0x3f3f3f3f;
int main(){
  cin >> t;
  while(t--){
    cin >> a >> b;
    if(a <= b) ans = min(ans,b);
  }
  if(ans == 0x3f3f3f3f) cout << -1;
  else cout << ans;
}