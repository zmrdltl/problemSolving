#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
char board[101][101];
int visited[101][101];
int bPower,wPower,n,m;
int bfs(int i, int j){
    int cnt = 1;
    char c = board[i][j];
    queue <pii> q;
    q.push({i,j});
    visited[i][j] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= m || 0 > ny || ny >= n) continue;
            if(visited[nx][ny] || board[nx][ny]!=c) continue;
            visited[nx][ny] = 1;
            cnt++;
            q.push({nx,ny});
        }
    }
    return cnt * cnt;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> board[i];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                if(board[i][j] == 'W') wPower += bfs(i,j);
                else bPower += bfs(i,j);
            }
        }
    }
    cout << wPower << ' ' << bPower <<'\n';
}