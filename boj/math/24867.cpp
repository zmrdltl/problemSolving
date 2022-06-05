#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll k, a, x, b, y, ans;


int main(){
  cin >> k >> a >> x >> b >> y;
  if (a < k) {
		ll timeleft = k - a;
		ll prod = timeleft * x;
		if (b < timeleft) {
			prod += (timeleft - b) * y;
		}
		ans = max(ans, prod);
	}

	if (b < k) {
		ll timeleft = k - b;
		ll prod = timeleft * y;
		if (a < timeleft) {
			prod += (timeleft - a) * x;
		}
		ans = max(ans, prod);
	}
  cout << ans;
}
