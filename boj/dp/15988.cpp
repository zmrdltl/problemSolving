#include <bits/stdc++.h>
#define ll long long
#define MOD 1'000'000'009
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
//i를 1,2,3으로 나타내는 방법의 수
//d[i] = d[i-1] + d[i-2] + d[i-3];
ll t, n, d[1000001];
ll dp(ll num){
    if(num <= 0) return 0;
    if(num == 1) return 1;
    if(num == 2) return 2;
    if(num == 3) return 4;
    ll &ret = d[num];
    if(ret != -1) return ret;
    ret = 0;
    ret += (dp(num - 1) % MOD + dp(num - 2) % MOD + dp(num - 3) % MOD) % MOD;
    return ret % MOD;
}

int main(){
    fastio;
    memset(d,-1,sizeof(d));
    cin >> t;
    while(t--){
        cin >> n;
        cout << dp(n) << '\n';
    }
}