#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll seg[1 << 21];

ll sum(ll node, ll start, ll end, ll left, ll right) {
	if (left <= start && right >= end) return seg[node];
	if (end < left || start > right) return 0;
	ll mid = (start + end) / 2;
	ll result = sum(node * 2, start, mid, left, right)
		+ sum(node * 2 + 1, mid + 1, end, left, right);
	return result;
}

int main() {
    fastio;
	int N, Q; cin >> N >> Q;
	const ll size = pow(2, (ll)log2(N) + 1);
	for (int i = 0; i < N; i++) cin >> seg[size + i];
	for (ll i = size - 1; i > 0; i--) seg[i] = seg[i * 2] + seg[i * 2 + 1];
	for (int i = 0; i < Q; i++) {
		int x, y, a, b; cin >> x >> y >> a >> b;
		if (x > y) swap(x, y);
		cout << sum(1, 1, size, x, y) << "\n";
		if (i == Q - 1) break;
		ll node = size + a - 1;
		ll diff = b - seg[node];
		for (; node > 0; node /= 2) seg[node] += diff;
	}
}