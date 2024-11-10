#include <bits/stdc++.h>
#define MOD 1234567
using namespace std;
using ll = long long;

ll d[2001];

ll dp(int num){
    if(num < 0) return 0;
    if(!num) return 1;
    ll &ret = d[num];
    if(ret!=-1) return ret;
    ret = 0;
    ret += dp(num-1) % MOD + dp(num-2) % MOD;
    return ret % MOD;
}
ll solution(int n) {
    memset(d,-1,sizeof(d));
    return dp(n);
}