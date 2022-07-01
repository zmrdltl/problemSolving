#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n, m, ans, sr, sc, ck[51][51];
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

char board[51][51];

void dfs(int r, int c, int path){
    if(r == sr && c == sc && path >= 4) {
        cout << "Yes"; 
        exit(0);
        return;
    }

    if(ck[r][c]) return;
    ck[r][c] = 1;

    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(board[nr][nc] != board[sr][sc]) continue;
        if(0 > nr || nr >= n || 0 > nc || nc >= m) continue;
        dfs(nr,nc,path+1);
    }

    ck[r][c] = 0;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(ck[i][j]) continue;
            sr = i, sc = j;
            dfs(i,j,0);
        }
    }

    cout << "No";
}