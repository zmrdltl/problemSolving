#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n, m, ck[101][101], cnt;
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0}; 
char pasture[101][101];

void bfs(int a, int b){
    ck[a][b] = 1;
    queue <pii> q;
    q.push({a,b});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(0 > nr || nr >= n || 0 > nc || nc >= m) continue;
            if(ck[nr][nc] || pasture[nr][nc] == '.') continue;
            ck[nr][nc] = 1;
            q.push({nr,nc});
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> pasture[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(ck[i][j] || pasture[i][j] == '.') continue;
            cnt++;
            bfs(i,j);
        }
    }
    cout << cnt << '\n';
}