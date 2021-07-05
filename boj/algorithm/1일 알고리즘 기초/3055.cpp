#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int r,c,sr,sc, escapeR, escapeC;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char board[51][51];
int waterDist[51][51], beaverDist[51][51];
queue <pii> waterQ;

void waterBFS(){
    queue <pii> q;
    while(!waterQ.empty()) {
        int x = waterQ.front().first;
        int y = waterQ.front().second;
        q.push({x,y});
        waterDist[x][y] = 0;
        waterQ.pop();
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= r || 0 > ny || ny >= c) continue;
            if(board[nx][ny] == 'X' || board[nx][ny] == 'D' || waterDist[nx][ny] != -1) continue;
            waterDist[nx][ny] = waterDist[x][y] + 1;
            q.push({nx,ny});
        }
    }
}

void beaverBFS(){
    queue <pii> q;
    q.push({sr,sc});
    beaverDist[sr][sc] = 0;    

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= r || 0 > ny || ny >= c) continue;
            if(board[nx][ny] == 'X' || board[nx][ny] == 'D' || beaverDist[nx][ny] != -1) continue;
            beaverDist[nx][ny] = beaverDist[x][y] + 1;
            q.push({nx,ny});
        }
    }
}

int getAns(){
    int ans = 0x3f3f3f3f;
    for(int i = 0; i < 4; i++){
        int nx = escapeR + dx[i];
        int ny = escapeC + dy[i];
        if(0 > nx || nx >= r || 0 > ny || ny >= c) continue;
        if(waterDist[nx][ny] > 0 && beaverDist[nx][ny] >= waterDist[nx][ny]) continue;
        if(beaverDist[nx][ny] == -1) continue;
        ans = min(ans,beaverDist[nx][ny] + 1);
    }
    return ans == 0x3f3f3f3f ? -1 : ans;
}

int main(){
    memset(waterDist,-1,sizeof(waterDist));
    memset(beaverDist,-1,sizeof(beaverDist));
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> board[i][j];
            if(board[i][j] == 'S') sr = i, sc = j;
            else if(board[i][j] == 'D') escapeR = i, escapeC = j;
            else if(board[i][j] == '*') waterQ.push({i,j});
        }
    }

    waterBFS();
    beaverBFS();

    int ans = getAns();

    if(ans == -1) cout << "KAKTUS";
    else cout << ans;
}