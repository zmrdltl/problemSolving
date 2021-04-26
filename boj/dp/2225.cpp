#include <bits/stdc++.h>
#define MOD 1'000'000'000
#define ll long long
using namespace std;
ll n,k;
ll d[201][201];
ll dp(ll k, ll n){
    if(k == 1) return 1;
    ll &ret = d[k][n];
    if(ret != -1) return ret;
    ret = 0;
    for(ll t = 0; t <= n; t++) ret += dp(k-1,t) % MOD;
    return ret % MOD;
}
int main(){
    cin >> n >> k;
    memset(d,-1,sizeof(d));
    cout << dp(k,n) << '\n'; 
}