#include <bits/stdc++.h>
#define ll long long
#define MOD 1'000'000'007
using namespace std;

ll dp[8] = {1,};
int main(){
    int D;
    cin >> D;
    while (D--) {
        ll tmp[8] = {0,};
        for (int i = 0; i < 8; i++) {
            tmp[0] = dp[1] + dp[3];
            tmp[1] = dp[0] + dp[2] + dp[3];
            tmp[2] = dp[1] + dp[3] + dp[4] + dp[5];
            tmp[3] = dp[0] + dp[1] + dp[2] + dp[5];
            tmp[4] = dp[2] + dp[5] + dp[6];
            tmp[5] = dp[3] + dp[2] + dp[4] + dp[7];
            tmp[6] = dp[4] + dp[7];
            tmp[7] = dp[5] + dp[6];
        }
        for(int i = 0; i < 8; i++){
            dp[i] = tmp[i] % MOD;
        }
    }
    cout << dp[0] << ' ';
}