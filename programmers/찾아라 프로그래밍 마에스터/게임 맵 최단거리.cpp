#include<vector>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;
using pii = pair<int,int>;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int bfs(int i,int j, int visited[101][101],vector<vector<int> > maps){
    int n = maps.size();
    int m = maps[0].size();
    queue <pii> q;
    q.push({i,j});
    visited[i][j] = 1;
    int d[101][101];
    memset(d,0,sizeof(d));
    d[0][0] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
            if(visited[nx][ny] || !maps[nx][ny] ) continue;
            visited[nx][ny] = 1;
            d[nx][ny] = d[x][y] + 1;
            q.push({nx,ny});
        }
    }
    return d[n-1][m-1] ? d[n-1][m-1] : -1;
}
int solution(vector<vector<int> > maps){
    int answer = 0;
    int visited[101][101];
    memset(visited,0,sizeof(visited));
    return bfs(0,0,visited,maps);
}