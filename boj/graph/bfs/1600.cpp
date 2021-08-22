#include <bits/stdc++.h>
using namespace std;
using tpiiii = tuple<int,int,int,int,int>;
int k,w,h,board[201][201], dist[201][201][2];
int dr[] = {0,0,1,-1,-1,-2,-2,-1,1,2,2,1};
int dc[] = {1,-1,0,0,-2,-1,1,2,2,1,-1,-2};
int bfs(){
    int ans = 0x3f3f3f3f;
    dist[0][0][0] = 0;
    queue <tpiiii> q;
    //현재 i,j일 때 남은 k횟수, 움직인 횟수
    q.push({0,0,k,0,0});
    while(!q.empty()){
        int r,c,cnt,stat,moved;
        tie(r, c, cnt, stat,moved) = q.front();
        //cout << "r,c,cnt,stat,dist : " << r << ' ' << c << ' ' << cnt << ' ' << stat << ' ' << dist[r][c][0] << ' ' << dist[r][c][1] << '\n';
        q.pop();
        if(r == h - 1 && c == w - 1) {
            // for(int i = 0; i < h; i++){
            //     for(int j = 0; j < w; j++){
            //         cout << '(' << dist[i][j][0] << ' ' << dist[i][j][1] << ')' << ' ';
            //     }
            //     cout << '\n';
            // }
            return moved;
        }

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(0 > nr || nr >= h || 0 > nc || nc >= w) continue;
            if(board[nr][nc] || dist[nr][nc][stat] >= 0) continue;
            dist[nr][nc][stat] = dist[r][c][stat] + 1;
            q.push({nr,nc,cnt,0,moved+1});
        }

        for(int i = 4; i < 12; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(0 > nr || nr >= h || 0 > nc || nc >= w) continue;
            if(board[nr][nc] || dist[nr][nc][stat] >= 0 || cnt - 1 < 0) continue;
            dist[nr][nc][1] = dist[r][c][stat] + 1;
            q.push({nr,nc,cnt - 1,1,moved+1});
        }
    }

    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j++){
    //         cout << '(' << dist[i][j][0] << ' ' << dist[i][j][1] << ')' << ' ';
    //     }
    //     cout << '\n';
    // }

    return -1;
}

int main(){
    memset(dist,-1,sizeof(dist));

    cin >> k >> w >> h;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> board[i][j];
        }
    }
    cout << bfs();
}
