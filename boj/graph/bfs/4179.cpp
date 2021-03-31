#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int r,c;
//TODO
string maze[1001];
int visited[1001][1001];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(int i,int j){
    queue <pii> q;
    q.push({i,j});
    visited[i][j] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
        }
    }
}

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        cin >> maze[i];
    }
}