#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<int> dp(n);
  for (int i = 0; i < n; i++) {
    dp[i] = arr[i];
    for (int j = 0; j < i; j++) {
        if (arr[j] < arr[i]) {
            dp[i] = max(dp[i], dp[j] + arr[i]);
        }
    }
  }

  int ans = *max_element(dp.begin(), dp.end());
  cout << ans << '\n';
}