#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;
using ll = long long;
ll dp[10001];

int main(){
	int n, k;
    cin >> n >> k;
	k = n + k - 1;
	
	dp[0] = dp[1] = 1;
	for(int i = 2; i <= k; i++) {
		dp[i] = 1;
		for(int j = i - 1; j > 0; j--){
			dp[j] = (dp[j - 1] + dp[j]) % 1000000000;
		}
	}
    cout << dp[n];
}