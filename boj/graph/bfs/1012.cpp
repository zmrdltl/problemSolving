#include <bits/stdc++.h>
using namespace std;
int testCase, n, m, k;
int field[51][51];
int check[51][51];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void bfs(int i, int j){
    queue <pair<int,int>> q;
    q.push({i,j});
    check[i][j] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
            if(check[nx][ny]) continue;
            if(field[nx][ny]){
                check[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
}

int main(){
    cin >> testCase;
    while(testCase--){
        int ans = 0;
        memset(field,0,sizeof(field));
        memset(check,0,sizeof(check));
        cin >> m >> n >> k;
        while(k--){
            int x,y;
            cin >> x >> y;
            field[y][x] = 1;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(field[i][j] && !check[i][j]){
                    bfs(i,j);
                    ans++;
                }
            }
        }
        cout << ans <<'\n';
    }
}