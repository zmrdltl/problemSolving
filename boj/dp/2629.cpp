#include <bits/stdc++.h>
using namespace std;
int a = 0, b = 0;
int sinker[31] ;
int arr[7];
int dp[40001][31];


int solved(int weight, int current) {
	if (weight == 0) return 1;
	if (current > a) return 0;

	int &ret = dp[weight][current];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = current; i <= a; i++) {
		ret = solved(abs(weight - sinker[i]), i + 1);
		ret = max(ret, solved(weight, i + 1));
		ret = max(ret, solved(weight + sinker[i], i + 1));
		return ret;
	}
}

int main() {
	cin >> a;
	for (int i = 1; i <= a; i++) cin >> sinker[i];
	cin >> b;
	for (int i = 1; i <= b; i++) {
		int temp;
		cin >> temp;
		memset(dp, -1, sizeof(dp));
		if (solved(temp, 1)) cout << 'Y';
		else cout << 'N';
		if (i != b) cout << ' ';
	}
}