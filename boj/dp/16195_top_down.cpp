#include <bits/stdc++.h>
#define MOD 1'000'000'009
#define ll long long
using namespace std;
ll t,n,m;
ll d[1001][1001];
ll dp(ll num, ll cnt){
    if(!num && !cnt) return 1;
    if(num < 0 || cnt < 0) return 0;
    ll &ret = d[num][cnt];
    if(ret != -1) return ret;
    ret = 0;
    ret = (dp(num-1,cnt-1) % MOD + dp(num-2,cnt-1) % MOD + dp(num-3,cnt-1) % MOD) % MOD;
    return ret;
}

int main(){
    cin >> t;
    memset(d,-1,sizeof(d));
    for(int i = 1; i <= 1000; i++){
        ll a = dp(1000,i);
    }
    while(t--){
        cin >> n >> m;
        ll ans = 0;
        for(int i = 1; i <= m; i++){
            ans = (ans % MOD + dp(n,i) % MOD) % MOD;
        }
        cout << ans << '\n';
    }
}