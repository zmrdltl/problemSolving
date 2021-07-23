#include <bits/stdc++.h>
using namespace std;
using tpiii = tuple<int,int,int>;
int n,m;
int maze[1001][1001];
int dist[1001][1001][2];
int isBroken[1001][1001];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

struct Coord {int x, y;} falled, escape;

int bfs(){
    memset(dist, -1, sizeof(dist));
    queue <tpiii> q;
    q.push({falled.x , falled.y, 0});
    dist[falled.x][falled.y][0] = 0;
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int w = get<2>(q.front());
        q.pop();
        if(x == escape.x && y == escape.y) return dist[x][y][w];

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(1 > nx || nx > n || 1 > ny || ny > m) continue;
            if(dist[nx][ny][w] != -1) continue;

            if(!maze[nx][ny]){
                dist[nx][ny][w] = dist[x][y][w] + 1;
                q.push({nx,ny,w});
            }
            if(!w && maze[nx][ny]){
                dist[nx][ny][1] = dist[x][y][0] + 1;
                q.push({nx,ny,1});
            }
        }
    }
    return -1;
}
int main(){
    cin >> n >> m;
    cin >> falled.x >> falled.y;
    cin >> escape.x >> escape.y;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> maze[i][j];
    }
    cout << bfs();
}