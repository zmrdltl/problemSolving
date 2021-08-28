#include <bits/stdc++.h>
#define pii pair<int,int>
#define INF 987654321
using namespace std;

int n, m, a, b, c;
vector<vector<pii>> g;

bool dijkstra(int k) {	//지나갈 수 있는 최대 수치심(edge weight)
	vector<int> dist(n + 1, INF);
	vector<bool> visit(n + 1, false);

	visit[a] = true;
	dist[a] = 0;

	priority_queue<pii> pq;	//dist, vertex의 element를 가진 priority queue(dist 오름차순)
	pq.push(make_pair(0,a));

	while (!pq.empty()) {
		int cur = pq.top().second; pq.pop();

		visit[cur] = true;
        if(cur==b) return dist[b]<=c;	//c이하로 b vertex를 갈 수 있는지 반환
		for (auto x : g[cur]) {	//cur와 연결된 다음 vertex에 대해
			if (visit[x.second]||(x.first>k))continue;	//만약 해당 vertex와 연결시켜주는 edge의 weight가 k를 넘으면 지나갈 수 없음
			if (dist[x.second] > dist[cur] + x.first) {
				dist[x.second] = dist[cur] + x.first;
				pq.push(make_pair(-dist[x.second], x.second));	//dist기준 min heap으로 만들어주기 위해 -1을 곱한 뒤 push
			}
		}
	}
	return false;
}

int main() {
	scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
	g = vector<vector<pii>>(n + 1, vector<pii>());

	for (int i = 0,u,v,w; i < m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(w, v));
		g[v].push_back(make_pair(w, u));
	}

	int left = -1,right=21;
    //loop invarient
    // 1. left<right
    // 2. dijkstra(left) = false & dijkstra(right) = true
	while (left + 1 < right) {
		int mid = (left + right) / 2;
		if (dijkstra(mid))
			right = mid;
		else left = mid;
	}
	printf("%d", right==21?-1:right);
	return 0;
}