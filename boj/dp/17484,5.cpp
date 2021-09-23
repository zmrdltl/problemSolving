#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, m, ans = INF;
int matrix[1001][1001], d[1001][1001][4];
int dc[] = {0, -1, 0, 1};
int dp(int r, int c, int dir){
    if(1 > c || c > m) return INF;
    if(r == n) return matrix[r][c];
    int &ret = d[r][c][dir];
    if(ret != INF) return ret;

    for(int i = 1; i <= 3; i++){
        if(i == dir) continue;
        ret = min(ret, matrix[r][c] + dp(r + 1, c + dc[i], i));
    }
    return ret;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> matrix[i][j];

    memset(d, INF, sizeof(d));

    for(int i = 1; i <= m; i++) ans = min(ans, dp(0,i,0));
    cout << ans;
}