#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
using pii = pair <int,int>;
char board[3001][3001];
int n, m, dist[3001][3001], startR, startC;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int bfs(){
    dist[startR][startC] = 0;
    queue <pii> q;
    q.push({startR, startC});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if(board[r][c] > '2') return dist[r][c];

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(0 > nr || nr >= n || 0 > nc || nc >= m) continue;
            if(board[nr][nc] == '1' || dist[nr][nc] >= 0) continue;

            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }
    return -1;
}

int main(){
    fastio;
    cin >> n >> m;
    memset(dist, -1, sizeof(dist));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == '2') startR = i, startC = j;
        }
    }
    int ans = bfs();
    if(ans == -1) cout << "NIE";
    else cout << "TAK\n" << ans;
}