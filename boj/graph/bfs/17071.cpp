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
        cout << curPos << ' ' << k << ' ' << sec << '\n';
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

// #include <bits/stdc++.h>
// using namespace std;
// #define inf 2'000'000'000
// int check[500001];
// int bro[500001];
// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int n, k, d = 0;
//     cin >> n >> k;
//     memset(bro, -1, sizeof(bro));
//     for (int i = k; i < 500001; i += d) bro[i] = d++;
//     queue<pair<int, int>> q;
//     q.push({n, 0});
//     check[n] = 1;
//     int ans = inf;
//     while (!q.empty()) {
//         auto [x, l] = q.front();
//         q.pop();
//         if (bro[x] >= l && (bro[x] - l) % 2 == 0) {
//             ans = min(ans, bro[x]);
//         }
//         int nx[3] = {x + 1, x - 1, 2 * x};
//         for (int i = 0; i < 3; i++) {
//             if (0 <= nx[i] && nx[i] <= 500000) {
//                 if (check[nx[i]] == 0) {
//                     check[nx[i]] = 1;
//                     q.push({nx[i], l + 1});
//                 }
//             }
//         }
//     }
//     if (ans == inf) {
//         cout << -1;
//         return 0;
//     }
//     cout << ans;
// }