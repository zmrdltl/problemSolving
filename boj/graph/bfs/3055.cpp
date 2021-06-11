#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int r,c,escapeRow, escapeCol, startRow, startCol, ans = 0x3f3f3f3f;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char board[51][51];
int ck[51][51], dist[51][51], waterDist[51][51];
queue <pii> waters;

void bfs(){
    memset(ck,0,sizeof(ck));
    queue <pii> q;
    ck[startRow][startCol] = 1;
    q.push({startRow,startCol});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(0 > nx || nx >= r || 0 > ny || ny >= c) continue;
            if(board[nx][ny] == 'D' || board[nx][ny] == 'X' || ck[nx][ny]) continue;
            ck[nx][ny] = 1;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx,ny});
        }
    }
}

void waterBFS(){
    queue <pii> q;
    while(!waters.empty()){
        int x = waters.front().first;
        int y = waters.front().second;
        q.push({x,y});
        ck[x][y] = 1;
        waters.pop();
    }
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(0 > nx || nx >= r || 0 > ny || ny >= c) continue;
            if(board[nx][ny] == 'D' || board[nx][ny] == 'X' || ck[nx][ny]) continue;
            ck[nx][ny] = 1;
            waterDist[nx][ny] = waterDist[x][y] + 1;
            q.push({nx,ny});
        }
    }
}

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> board[i][j];
            if(board[i][j] == 'S') startRow = i, startCol = j;
            if(board[i][j] == 'D') escapeRow = i, escapeCol = j;
            if(board[i][j] == '*') waters.push({i,j});
        }
    }   
    waterBFS();
    bfs();
    
    for(int i = 0; i < 4; i++){
        int nx = escapeRow + dx[i];
        int ny = escapeCol + dy[i];
        if(0 > nx || nx >= r || 0 > ny || ny >= c) continue;
        if(dist[nx][ny] && dist[nx][ny] < waterDist[nx][ny]) ans = min(ans, dist[nx][ny] + 1);
        if(!waterDist[nx][ny] && dist[nx][ny] ) ans = min(ans, dist[nx][ny] + 1);
        if(board[nx][ny] == 'S') ans = 1;
    }

    if(ans == 0x3f3f3f3f) cout << "KAKTUS";
    else cout << ans << '\n';
}