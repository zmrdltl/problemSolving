#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n, m, t, board[101][101], d[101][101];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
struct Coord{ int x, y; } gram;

int bfs(int endX, int endY){
    memset(d,-1,sizeof(d));
    d[0][0] = 0;
    queue <pii> q;
    q.push({0,0});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
            if(board[nx][ny] == 1 || d[nx][ny] != -1) continue;
            d[nx][ny] = d[x][y] + 1;
            q.push({nx,ny});
        }
    }
    if(d[endX][endY] == -1) return 0x3f3f3f3f;
    return d[endX][endY];
}

int main(){
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 2) gram = {i,j};
        }
    }
    int ans = min(bfs(gram.x,gram.y) + n - gram.x + m - gram.y - 2 , bfs(n-1,m-1));
    if(ans > t) cout << "Fail";
    else cout << ans;
}