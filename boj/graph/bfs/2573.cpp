#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int board[301][301], copyBoard[301][301], ck[301][301];
int n, m, year;

int notMelt(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(board[i][j]) return 1;
    return 0;
}

void meltIce(int i,int j){
    queue <pii> q;
    q.push({i,j});
    ck[i][j] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        copyBoard[x][y] = board[x][y];
        int zeroArea = 0;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >=n || 0 > ny || ny >= m) continue;
            if(ck[nx][ny]) continue;
            if(board[nx][ny]) {
                ck[nx][ny] = 1;
                q.push({nx,ny});
            }
            else zeroArea++;
        }
        if(copyBoard[x][y] - zeroArea >= 0) copyBoard[x][y] -= zeroArea;
        else copyBoard[x][y] = 0;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            board[i][j] = copyBoard[i][j];
}

int getArea(){
    int ck[301][301] = {0};
    int area = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] && !ck[i][j]){
                area++;
                queue <pii> q;
                q.push({i,j});
                ck[i][j] = 1;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int i = 0 ; i < 4; i++){
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
                        if(!board[nx][ny] || ck[nx][ny]) continue;
                        ck[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
    return area;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    int area = getArea();
    while(getArea() == 1){
        memset(ck,0,sizeof(ck));
        memset(copyBoard,0,sizeof(copyBoard));
        year++;
        for(int i = 0; i < n; i++)
            for(int j = 0 ; j < m; j++)
                if(board[i][j] && !ck[i][j])
                    meltIce(i,j);
    }

    if(notMelt()) cout << year << '\n';
    else cout << 0 << '\n';
}