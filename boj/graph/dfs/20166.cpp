#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
string board[11];
int n,m,k;
int dr[] = {-1,-1,-1,0,0,1,1,1};
int dc[] = {-1,0,1,-1,1,-1,0,1};

map <string,int> caseMap;
void dfs(int r, int c, int depth, string s){
    if(depth == 5) return;
    caseMap[s]++;
    for(int dir = 0; dir < 8; dir++){
        int nr = r + dr[dir];
        int nc = c + dc[dir];

        if(0 > nr) nr = n - 1;
        if(0 > nc) nc = m - 1;
        if(nr >= n) nr = 0;
        if(nc >= m) nc = 0;
        dfs(nr,nc,depth+1,s+board[nr][nc]);
    }
}

int main(){
    fastio;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> board[i];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            string start = "";
            dfs(i,j,0,start + board[i][j]);
        }
    }

    while(k--){
        string s;
        cin >> s;
        cout << caseMap[s] << '\n';
    }
}