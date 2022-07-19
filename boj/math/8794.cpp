#include <bits/stdc++.h>
using namespace std;

int z, n, m, l, ans;

int main(){
  cin >> z;
  while(z--){
    ans = 0;
    cin >> n >> m >> l;
    n -= (m-l+1);
    ans += n / m;
    if(n % m) ans++;
    if(l == 1) ans++;
    cout << ans << '\n';
  }
}