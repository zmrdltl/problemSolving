#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
int ck[101][101], n, m;

int bfs(vector<vector<int>> maps){
    queue <pii> q;
    q.push({0,0});
    ck[0][0] = 1;
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if(r == n - 1 && c == m - 1) return ck[r][c];
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(0 > nr || nr >= n || 0 > nc || nc >= m) continue;
            if(ck[nr][nc] || !maps[nr][nc]) continue;
            ck[nr][nc] = ck[r][c] + 1;
            q.push({nr,nc});
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps){
    n = maps.size();
    m = maps[0].size();
    memset(ck, 0, sizeof(ck));
    return bfs(maps);
}