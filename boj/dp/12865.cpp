#include <bits/stdc++.h>
using namespace std;

pair<int, int> product[100];
int dp[100][100001],n, limit;
int main() {
	cin >> n >> limit;
	for (int i = 0; i < n; i++) cin >> product[i].first >> product[i].second;
	for (int i = 0; i <= limit; i++) {
		if (product[0].first <= i) dp[0][i] = product[0].second;
		else dp[0][i] = 0;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= limit; j++) {
			if (product[i].first <= j) 
                dp[i][j] = max(dp[i - 1][j], product[i].second + dp[i - 1][j - product[i].first]);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n - 1][limit] << endl;
}