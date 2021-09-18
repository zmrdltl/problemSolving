#include <bits/stdc++.h>
using namespace std;
using pii = pair <int, int>;
int n, m, ans, groupNum, groupCk[100001];
int board[1001][1001], ck[1001][1001];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
unordered_map <int, int> areaPerGroup;

void paintArea(int i, int j){
    groupNum++;
    ck[i][j] = 1;
    queue <pii> q;
    q.push({i, j});
    int cnt = 1;
    board[i][j] = groupNum;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(0 > nr || nr >= n || 0 > nc || nc >= m) continue;
            if(!board[nr][nc] || ck[nr][nc]) continue;
            board[nr][nc] = groupNum;
            ck[nr][nc] = 1;
            cnt++;
            q.push({nr, nc});
        }
    }

    areaPerGroup[groupNum] = cnt;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(board[i][j] && !ck[i][j])
                //새로운 영역
                paintArea(i, j);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j]) continue;

            int cnt = 1;

            for(int d = 0; d < 4; d++){
                int nr = i + dr[d];
                int nc = j + dc[d];
                if(board[nr][nc] && !groupCk[board[nr][nc]]){
                    groupCk[board[nr][nc]] = 1;
                    cnt += areaPerGroup[board[nr][nc]];
                }
            }

            for(int d = 0; d < 4; d++){
                int nr = i + dr[d];
                int nc = j + dc[d];
                groupCk[board[nr][nc]] = 0;
            }

            ans = max(ans, cnt);
        }
    }
    
    cout << ans;
}