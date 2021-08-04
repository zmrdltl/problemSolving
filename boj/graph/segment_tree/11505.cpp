#include <bits/stdc++.h>
#define MOD 1'000'000'007
using namespace std;
using ll = long long;
ll n, m, k, num[1000001];
ll tree[4000001];

ll init(ll start, ll end, ll piv){
    if(start == end) return tree[piv] = num[start];
    ll mid = (start + end) / 2;
    return tree[piv] = init(start, mid, piv * 2) * init(mid + 1, end, piv * 2 + 1) % MOD;
}

ll mul(ll start, ll end, ll piv, ll left, ll right){
    if(left > end || right < start) return 1;
    if(left <= start && end <= right) return tree[piv];
    ll mid = (start + end) / 2;
    return mul(start, mid, piv * 2, left, right) * mul(mid + 1, end, piv * 2 + 1, left, right)  % MOD;
}

ll update(ll start, ll end, ll piv, ll idx, ll diff){
    if(idx < start || idx > end) return tree[piv];
    if(start == end ) return tree[piv] = diff;
    ll mid = (start + end ) / 2;

    return tree[piv] = 
    update(start, mid, piv * 2, idx, diff) *
    update(mid + 1, end, piv * 2 + 1, idx, diff) % MOD;
}

int main(){
    cin >> n >> m >> k;
    for(ll i = 0; i < n; i++) cin >> num[i];
    init(0,n-1,1);
    for(ll i = 0,a,b,c; i < m + k; i++){
        cin >> a >> b >> c;
        if(a == 1) update(0,n-1,1,b-1,c);
        else cout << mul(0,n-1,1,b-1,c-1) << '\n';
    }

}