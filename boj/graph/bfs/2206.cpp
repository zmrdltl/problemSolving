#include <bits/stdc++.h>
using namespace std;
int n,m;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int visited[1001][1001][2];
int board[1001][1001];

int bfs(int i,int j){
    queue <tuple<int,int,int>> q;
    q.push({i,j,0});
    visited[i][j][0] = 1;

    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int w = get<2>(q.front());
        q.pop();
        if(x==n-1 && y == m-1) return visited[x][y][w];
        for(int i = 0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
            if(visited[nx][ny][w]) continue;

            //갈 수 있는 곳이면 이전 state + 1이 현재까지의 경로
            if(!board[nx][ny]){
                visited[nx][ny][w] = visited[x][y][w] + 1;
                q.push({nx,ny,w});
            }
            
            //부순 적이 없고 현재는 벽이라면
            if(!w && board[nx][ny]){
                visited[nx][ny][1] = visited[x][y][0] + 1;
                q.push({nx,ny,1});
            }

            
        }
    }
    return -1;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%1d",&board[i][j]);
    cout << bfs(0,0);
}