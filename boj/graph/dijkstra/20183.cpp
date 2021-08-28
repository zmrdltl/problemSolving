//TODO
#include <bits/stdc++.h>
#define ull unsigned long long
#define pli pair<ull,int>
#define pii pair<int,int>
using namespace std;

int n, m, a, b,ans;
ull c;
vector<vector<pii>> g;
typedef struct {
	int e;
	ull c;
	int n;
}rhs;
struct compare{
	bool operator()(rhs a, rhs b) {
		return a.e > b.e;
	}
};

int main() {
	scanf("%d%d%d%d%lld", &n, &m, &a, &b, &c);
	g = vector<vector<pii>>(n + 1, vector<pii>());

	for (int i = 0,u,v,w; i < m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(w, v));
		g[v].push_back(make_pair(w, u));
	}
	   
	vector<int> cost(n + 1, INT_MAX);
	vector<bool> visit(n + 1, false);

	visit[a] = true;
	cost[a] = 0;

	priority_queue< rhs, vector<rhs>, compare > pq;
	pq.push({ 0,0,a });

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		visit[cur.n] = true;
		for (auto x : g[cur.n]) {
			int emb = max(cur.e, x.first);
			ull ndist = cur.c + x.first;
			if (!visit[x.second] && (cost[x.second] > emb) && (ndist <= c)) {
				cost[x.second] = emb;
				pq.push({ emb,ndist,x.second });
			}
		}
	}
	printf("%d", cost[b] == INT_MAX ? -1 : cost[b]);

	return 0;
}