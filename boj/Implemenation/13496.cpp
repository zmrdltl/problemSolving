#include <bits/stdc++.h>
using namespace std;
int n, s, d, t, ans;
int main(){
  cin >> t;
  for(int i = 1; i <= t; i++){
    cin >> n >> s >> d;
    ans = 0;
    for(int j = 0, a, b; j < n; j++){
      cin >> a >> b;
      if(s * d >= a) ans += b;
    }
    cout << "Data Set " << i <<":\n" << ans << '\n' << '\n';
  }
}