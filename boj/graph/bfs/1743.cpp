#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int passage[101][101];
int visited[101][101];
int n,m,k,ans;

int bfs(int i, int j){
    queue <pii> q;
    q.push({i,j});
    visited[i][j] = 1;
    int area = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
            if(visited[nx][ny] || !passage[nx][ny]) continue;
            visited[nx][ny] = 1;
            area++;
            q.push({nx,ny});
        }
    }
    return area;
}

int main(){
    cin >> n >> m >> k;
    
    for(int i = 0; i < k; i++){
        int r,c;
        cin >> r >> c;
        passage[r-1][c-1] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j] && passage[i][j])
                ans = max(ans,bfs(i,j));
        }
    }
    cout << ans <<'\n';
}