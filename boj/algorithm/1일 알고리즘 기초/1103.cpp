#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n, m, board[51][51], d[51][51], cycleCk[51][51];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dfs(int x, int y){
    if(cycleCk[x][y]) return INF;

    int &ret = d[x][y];
    if(ret != -1) return ret;
    ret = 1;
    cycleCk[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i] * board[x][y];
        int ny = y + dy[i] * board[x][y];
        if(1 > nx || nx > n || 1 > ny || ny > m) continue;
        if(!board[nx][ny]) continue;
        ret = max(ret,dfs(nx,ny) + 1);
    }
    cycleCk[x][y] = 0;
    return ret;
}

int main(){
    memset(d,-1,sizeof(d));
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char x;
            cin >> x;
            if(x == 'H') board[i][j] = 0;
            else board[i][j] = x - '0';
        }
    }
    int ans = dfs(1,1);
    if(ans >= INF) cout << -1;
    else cout << ans;
}
