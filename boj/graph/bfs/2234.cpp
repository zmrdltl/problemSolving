#include <bits/stdc++.h>
using namespace std;
using pii = pair <int,int>;
int n, m, wall[51][51], ck[51][51], roomCnt, biggestRoomSize, biggestRoomSize2;
int dr[] = {0, -1, 0, 1};
int dc[] = {-1, 0, 1, 0};
int bfs(int i, int j){
    int roomSize = 1;
    ck[i][j] = 1;
    queue <pii> q;
    q.push({i, j});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        int wallInfo = wall[r][c];
        for(int dir = 0; dir < 4; dir++){
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if(0 > nr || nr >= n || 0 > nc || nc >= m) continue;
            //벽있다면 continue;
            if((wallInfo & (1 << dir)) || ck[nr][nc]) continue;
            roomSize++;
            q.push({nr, nc});
            ck[nr][nc] = 1;
        }
    }
    return roomSize;
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> wall[i][j];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!ck[i][j]){
                biggestRoomSize = max(biggestRoomSize, bfs(i, j));
                roomCnt++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int dir = 1; dir <= 8; dir <<= 1){
                if(wall[i][j] & dir){
                    memset(ck, 0, sizeof(ck));
                    wall[i][j] -= dir;
                    biggestRoomSize2 = max(biggestRoomSize2, bfs(i, j));
                    wall[i][j] += dir;
                }
            }
        }
    }

    cout << roomCnt << '\n' << biggestRoomSize << '\n' << biggestRoomSize2 << '\n';
}