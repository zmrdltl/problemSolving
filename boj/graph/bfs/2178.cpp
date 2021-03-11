#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
string maze[101];
int ck[101][101];
int d[101][101];
int n,m;
int bfs(int i, int j){
    queue <pii> q;
    q.push({i,j});
    ck[i][j] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0>nx || nx >= n || 0 > ny || ny >= m) continue;
            if(ck[nx][ny] || maze[nx][ny]=='0') continue;
            d[nx][ny] = d[x][y] + 1;
            ck[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
    return d[n-1][m-1] + 1;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> maze[i];
    cout << bfs(0,0);
}