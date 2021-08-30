#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MAX = 100001;
const int INF = 0x3f3f3f3f;
int N, M, X;
vector<int> v[2][MAX];
bool visited[MAX];
int dfs(int cur, int type) {
	int ret = 1;
	visited[cur] = true;
	for (auto i : v[type][cur]) {
		if (!visited[i])
			ret += dfs(i, type);
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> X;
	while (M--) {
		int a, b;
		cin >> a >> b;
		v[0][b].push_back(a);
		v[1][a].push_back(b);
	}
	int ans1 = dfs(X, 0);
	memset(visited, false, sizeof(visited));
	int ans2 = N - dfs(X, 1) + 1;
	cout << ans1 << " " << ans2 << "\n";
}