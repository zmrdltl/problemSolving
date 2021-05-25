#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int,int>;
int n;
int ck[51][51], board[51][51], dist[51][51]; //마지막 0은 부순상태, 안부순 상태
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int bfs(){
    queue <pii> q;
    q.push({0,0});
    ck[0][0] = 0;
    int ans = 0x3f3f3f3f;
    int cnt = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= n || 0 > ny || ny >= n) continue;
            if(!ck[nx][ny]) continue;
            if(!board[nx][ny]){
                if(ck[nx][ny] == -1 || ck[nx][ny] > ck[x][y] + 1){
                    ck[nx][ny] = ck[x][y] + 1;
                    q.push({nx,ny});
                }
            }
            else{
                if(ck[nx][ny] == -1 || ck[nx][ny] > ck[x][y]){
                    ck[nx][ny] = ck[x][y];
                    q.push({nx,ny});
                }
            }
        }
    }
    return ck[n-1][n-1];
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%1d",&board[i][j]);
        }
    }
    memset(ck,-1,sizeof(ck));
    cout << bfs() << '\n';
}