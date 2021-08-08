#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int ck[1001][1001], board[1001][1001], m, n;
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

int bfs(int i, int j){
    queue <pii> q;
    q.push({i,j});
    ck[i][j] = 1;
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(0 > nr || nr >= m || 0 > nc || nc >= n) continue;
            if(ck[nr][nc] || board[nr][nc] == 1) continue;
            ck[nr][nc] = 1;
            q.push({nr,nc});
        }
    }

    for(int i = 0; i < n; i++)
        if(ck[m-1][i]) return 1;

    return 0;
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%1d",&board[i][j]);

    for(int i = 0; i < n; i++)
        if(!ck[0][i] && !board[0][i] )
            if(bfs(0,i)) goto SUCCESS;

    cout << "NO"; return 0;

    SUCCESS:
    cout << "YES";

}