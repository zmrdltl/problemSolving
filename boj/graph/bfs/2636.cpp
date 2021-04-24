#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n, m, hour, cnt;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int board[101][101],ck[101][101],ckAir[101][101], boardCopy[101][101], air[101][101];

bool isNotMelt(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(board[i][j]) return 1;
    return 0;
}

int getCheeseArea(){
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(board[i][j])cnt++;
    return cnt;
}

void updateBoard(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            board[i][j] = boardCopy[i][j];
}

void checkAir(int i, int j){
    queue <pii> q;
    q.push({i,j});
    ckAir[i][j] = 1;
    board[i][j] = -1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
            if(board[x][y]<=0 && board[nx][ny]!=1) board[nx][ny] = -1;
            if(ckAir[nx][ny] || board[nx][ny] == 1) continue;
            ckAir[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
}

void bfs(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!ck[i][j] && board[i][j]){
                queue <pii> q;
                q.push({i,j});
                ck[i][j] = 1;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    boardCopy[x][y] = board[x][y];
                    for(int i = 0; i < 4; i++){
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
                        if(board[nx][ny] < 0) boardCopy[x][y] = 0;
                        if(ck[nx][ny]) continue;
                        ck[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    while(isNotMelt()){
        memset(ckAir,0,sizeof(ckAir));
        memset(ck,0,sizeof(ck));
        memset(boardCopy,0,sizeof(boardCopy));
        cnt = getCheeseArea();
        checkAir(0,0);
        bfs();
        updateBoard();
        hour++;
    }
    cout << hour << '\n' << cnt;
}