#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int n;
struct Road { int x, y ,cost, dir; };
int bfs(vector<vector<int>> board){
    int ans = INF;
    queue <Road> q;

    q.push({0,0,0,-1});
    board[0][0] = 1;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        int cost = q.front().cost;
        q.pop();
        if(x == n-1 && y == n-1) {ans = min(ans,cost); continue;}
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nc = 0;
            if(0 > nx || nx >= n || 0 > ny || ny >= n) continue;
            if(board[nx][ny] == 1) continue;

            if(dir == -1 || dir == k) nc = cost + 100;

            else if(dir != k) nc = cost + 600;

            if(!board[nx][ny] || board[nx][ny] >= nc){
                board[nx][ny] = nc;
                q.push({nx,ny,nc,k});
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return ans;
}

int solution(vector<vector<int>> board) {
    n = board.size();
    return bfs(board);
}