#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
struct Consulting {int t, p; };
int n, d[1500001];
vector <Consulting> consult;

int dp(int i){
    if(i >= n) return 0;
    int &ret = d[i];
    if(ret != -1) return ret;
    ret = 0;
    if(i + consult[i].t <= n) ret = max(ret,dp(i+consult[i].t) + consult[i].p);
    ret = max(ret, dp(i+1));
    return ret;
}
int main(){
    memset(d,-1,sizeof(d));
    fastio;
    cin >> n;
    consult.resize(n);
    for(int i = 0,t,p; i < n; i++) cin >> t >> p, consult[i] = {t,p};
    cout << dp(0);
}