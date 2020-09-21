#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, m, ans;
int d[51][51];
int ck[51][51];
char map[51][51];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int bfs(int i,int j){
    int distance = 0;
    queue <pair<int,int>> q;

    q.push({i,j});
    ck[i][j] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i <4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
            if(map[nx][ny]=='L' && ck[nx][ny]==0){
                ck[nx][ny] = 1;
                q.push({nx,ny});
                d[nx][ny] = d[x][y] + 1;
                distance = max(distance,d[nx][ny]);
            }
        }
    }
    return distance;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j<m; j++)
            cin >> map[i][j];

    for(int i = 0; i < n; i++){
        for(int j = 0 ;j <m; j++){
            if(map[i][j]=='L') ans = max(ans,bfs(i,j));
            memset(d,0,sizeof(d));
            memset(ck,0,sizeof(ck));
        }
    }
    
    cout << ans <<'\n';
}