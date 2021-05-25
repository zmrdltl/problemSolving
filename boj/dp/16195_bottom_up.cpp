#include <bits/stdc++.h>
#define MOD 1'000'000'009
#define ll long long
using namespace std;
ll t, n, m;
ll d[1001][1001];
int main(){
    cin >> t;
    d[1][1] = 1;
    d[2][1] = 1;
    d[2][2] = 1;
    d[3][1] = 1;
    d[3][2] = 2;
    d[3][3] = 1;
    
    for(int i = 4; i <= 1000; i++){
        for(int j = 2; j <= i; j++){
            d[i][j] += (d[i-1][j-1] % MOD + d[i-2][j-1] % MOD + d[i-3][j-1] % MOD) % MOD;
        }
    }

    while(t--){
        cin >> n >> m;
        ll ans = 0;
        for(int i = 1; i <= m; i++) ans = (ans % MOD + d[n][i] % MOD) % MOD;
        cout << ans << '\n';
    }
}