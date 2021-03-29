#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()

int main() {
	fastio;
	string a, b; cin >> a >> b;
	while (sz(a) > 1 && a[0] == '0') a.erase(0, 1);
	while (sz(b) > 1 && b[0] == '0') b.erase(0, 1);
	string res(max(sz(a), sz(b)), '0');
	bool carry = 0;
	for (int i = 0; i < sz(res); i++) {
		int temp = carry;
		carry = 0;
		if (i < sz(a)) temp += a[sz(a) - 1 - i] - '0';
		if (i < sz(b)) temp += b[sz(b) - 1 - i] - '0';
		if (temp >= 2) {
			carry = 1;
			temp -= 2;
		}
		res[sz(res) - 1 - i] = temp + '0';
	}
	if (carry) res.insert(res.begin(), '1');
	cout << res << '\n';
}