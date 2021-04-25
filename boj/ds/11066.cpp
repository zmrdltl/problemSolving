#include <bits/stdc++.h>
using namespace std;
int t, n;
int d[501][501];
int cost[501];
int dp(int i, int j){
    if(i == j) return 0;
    int &ret = d[i][j];
    if(ret != -1) return ret;
    ret = 0x3f3f3f3f;
    for(int x = i; x < j; x++){
        ret = min(ret, dp(i,x) + dp(x+1,j) + cost[j] - cost[i-1]);
    }
    return ret;
}

int main(){
    cin >> t;

    while(t--){
        cin >> n;
        memset(d,-1,sizeof(d));
        for(int i = 1; i <= n; i++) cin >> cost[i], cost[i] += cost[i-1];
        cout << dp(1,n) << '\n';
    }
}