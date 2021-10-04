#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, cost[16][16], d[16][1 << 16];

int dp(int cur, int status){
    if(status == (1 << n) - 1){
        if(cost[cur][0] == 0) return INF;
        return cost[cur][0];
    }
    int &ret = d[cur][status];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = 0; i < n; i++){
        if(!cost[cur][i]) continue;
        if((status & (1 << i)) == (1 << i)) continue; //이미 들렀던 도시면
        ret = min(ret, cost[cur][i] + dp(i, status | 1 << i));
    }
    return ret;
}

int main(){
    memset(d, -1, sizeof(d));
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> cost[i][j];
        }
    }
    cout << dp(0, 1);
}