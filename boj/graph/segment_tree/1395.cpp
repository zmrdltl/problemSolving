#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct SegTree {
	int tree[1 << 18]; //arr[0, n-1] -> tree[sz, sz + n - 1]
	int sz = 1 << 17;
	bitset<1 << 18> lazy;

	void construct() {
		for (int i = sz - 1; i > 0; i--) {
			tree[i] = tree[i << 1] + tree[i << 1 | 1];
		}
	}
    
	void propagate(int node, int nodeL, int nodeR) {
		if (lazy[node]) {
			if (node < sz) {
				lazy[node << 1].flip();
				lazy[node << 1 | 1].flip();
			}
			tree[node] = (nodeR - nodeL + 1) - tree[node];
			lazy[node] = 0;
		}
	}
	//[l, r] flip
	void update(int L, int R, int nodeNum, int nodeL, int nodeR) {
		propagate(nodeNum, nodeL, nodeR);
		if (R < nodeL || nodeR < L) return;
		if (L <= nodeL && nodeR <= R) {
			lazy[nodeNum].flip();
			propagate(nodeNum, nodeL, nodeR);
			return;
		}
		int mid = nodeL + nodeR >> 1;
		update(L, R, nodeNum << 1, nodeL, mid);
		update(L, R, nodeNum << 1 | 1, mid + 1, nodeR);
		tree[nodeNum] = tree[nodeNum << 1] + tree[nodeNum << 1 | 1];
	}
	void update(int l, int r) {
		update(l, r, 1, 1, sz);
	}
	//[l, r] : 1-indexed
	int query(int L, int R, int nodeNum, int nodeL, int nodeR) {
		propagate(nodeNum, nodeL, nodeR);
		if (R < nodeL || nodeR < L) return 0;
		if (L <= nodeL && nodeR <= R) return tree[nodeNum];
		int mid = nodeL + nodeR >> 1;
		return query(L, R, nodeNum << 1, nodeL, mid) + query(L, R, nodeNum << 1 | 1, mid + 1, nodeR);
	}
	int query(int l, int r) {
		return query(l, r, 1, 1, sz);
	}
} ST;

int main() {
	fastio;
	int n, q; cin >> n >> q;
	while (q--) {
		int t, a, b; cin >> t >> a >> b;
		if (t) cout << ST.query(a, b) << '\n';
		else ST.update(a, b);
	}
}