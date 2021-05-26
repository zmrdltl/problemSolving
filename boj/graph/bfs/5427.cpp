#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int visited[1001][1001];
int fireVisited[1001][1001];
int w,h,t,r,c;
struct Coord { int r, c; };
vector <Coord> fireCoords, escapeCoords;

void fireBFS(string building[1001]){
    queue <pii> q;
    for(auto f : fireCoords) q.push({f.r,f.c}),fireVisited[f.r][f.c] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= h || 0 > ny || ny >= w) {
                if(building[x][y] == '.' || building[x][y] == '@') {
                    Coord c = {x,y};
                    escapeCoords.push_back(c);
                }
                continue;
            }
            if(building[nx][ny] =='#' || fireVisited[nx][ny] != -1) continue;
            fireVisited[nx][ny] = fireVisited[x][y] + 1;
            q.push({nx,ny});
        }
    }
}


void bfs(string building[1001]){
    queue <pii> q;
    q.push({r,c});
    visited[r][c] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= h || 0 > ny || ny >= w) { 
                if(building[x][y] == '.' || building[x][y] == '@') escapeCoords.push_back({x,y});
                continue; 
            }
            if(building[nx][ny] =='#' || visited[nx][ny] != -1) continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx,ny});
        }
    }
}

bool isSafe(int escapeRow, int escapeCol){
    if(escapeRow == -1 || escapeCol == -1) return false;
    if(visited[escapeRow][escapeCol] == -1) return false;
    if(visited[escapeRow][escapeCol] >= fireVisited[escapeRow][escapeCol] && fireVisited[escapeRow][escapeCol] != -1) {
        return false;
    }
    return true;
}

int main(){
    cin >> t;
    while(t--){
        int ans = 0x3f3f3f3f;
        memset(visited,-1,sizeof(visited));
        memset(fireVisited,-1,sizeof(fireVisited));
        fireCoords.clear();
        escapeCoords.clear();
        string building[1001];
        cin >> w >> h;
        for(int i = 0; i < h; i++){
            cin >> building[i];
            for(int j = 0; j < w; j++){
                if(building[i][j] == '@') r = i, c = j;
                if(building[i][j] == '*') fireCoords.push_back({i,j});
            }
        }
        fireBFS(building);
        bfs(building);
        for(auto e : escapeCoords){
            if(isSafe(e.r,e.c)) ans = min(ans,visited[e.r][e.c] + 1);
        }
        if(ans == 0x3f3f3f3f) cout << "IMPOSSIBLE\n";
        else cout << ans << '\n';
    }
}