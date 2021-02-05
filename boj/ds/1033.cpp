#include <bits/stdc++.h>
using namespace std;

int n;
int tower[500005], ans[500005];
stack<pair<int, int>> s;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> tower[i];

	for (int i = 1; i <= n; i++) {
		if (s.empty())
			s.push({ i, tower[i] });
		else {
			while (s.top().second < tower[i]) {
				s.pop();
				if (s.empty()) break;
			}
			if (!s.empty())
				ans[i] = s.top().first;
			s.push({ i, tower[i] });
		}
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}