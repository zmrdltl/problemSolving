#include <iostream>
#define ll long long
using namespace std;
ll a[1000000], tree[3000000];
int x1, x2, n, m, k;

ll init(int node, int start, int end){
	if (start == end) return tree[node] = a[start];
	else return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}

void update(int node, int start,int end, int i, ll diff){
	if (i<start || i>end) return;
	tree[node] += diff;
	if (start != end){
		update(node * 2, start, (start + end) / 2, i, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, i, diff);
	}
}

ll sum(int node, int start, int end, int i, int j){
	if (i > end || j < start) { return 0; }
	if (i <= start && j >= end) { return tree[node]; }
	return sum(node * 2, start, (start + end) / 2, i, j) + sum(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld",&a[i]);
	init(1, 0, n - 1);
	m += k;
	while (m--){
		scanf("%d", &x1);
		if (x1 == 1){
			ll x3;
			scanf("%d %lld", &x2, &x3);
			ll diff = x3 - a[x2-1];
			a[x2 - 1] = x3;
			update(1, 0, n - 1, x2-1, diff);
		}
		else if(x1==2){
			int x3;
			scanf("%d %d", &x2, &x3);
			printf("%lld\n", sum(1, 0, n - 1, x2-1, x3-1));
		}
	}
}