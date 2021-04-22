#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, k, acc;
bool ck[500001][2];

int bfs() {
    queue <pii> q;
    //현 위치, 시간초
	q.push({ n,0 });
	ck[n][0] = 1;
	while (!q.empty()) {
		if (ck[k][acc & 1]) return acc;
		int curPos = q.front().first;
        int sec = q.front().second;
        q.pop();

		if (sec > acc) k += (++acc);
		if (k > 500000) return -1;

		int dir[3] = { -1,1,curPos };
		for (auto d : dir) {
			if (curPos + d < 0 || curPos + d > 500000) continue;
			if (ck[curPos + d][(sec + 1) & 1]) continue;
			q.push({ curPos + d,sec + 1});
			ck[curPos + d][(sec + 1) & 1] = 1;
		}
	}
}

int main() {
    cin >> n >> k;
    cout << bfs();
}