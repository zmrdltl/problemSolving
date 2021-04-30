#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n, m, light[101][101], visited[101][101], canMove[101][101];
struct Info { int x, y; };
vector <Info> room[101][101];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int bfs(){
    int ans = 0;
    visited[1][1] = 1;
    light[1][1] = 1;
    queue <pii> q;
    q.push({1,1});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(auto &r : room[x][y]) light[r.x][r.y] = 1; 

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(1 > nx || nx > n || 1 > ny || ny > n) continue;
            canMove[nx][ny] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(!light[i][j] || visited[i][j] || !canMove[i][j]) continue;
                visited[i][j] = 1;
                q.push({i,j});
            }
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j <=n;j++){
            if(light[i][j]) ans++;
        }
    }

    return ans;
}

int main(){
    cin >> n >> m;
    while(m--){
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        room[x][y].push_back({a,b});
    }
    cout << bfs();
}