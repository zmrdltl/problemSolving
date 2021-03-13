#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
char ground[251][251];
int visited[251][251];
int sheepCnt,wolfCnt,r,c;

void bfs(int i, int j){
    queue <pii> q;
    q.push({i,j});
    visited[i][j] = 1;
    int s = 0;
    int w = 0;
    if(ground[i][j] == 'o') s++;
    else if(ground[i][j] == 'v') w++;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= r || 0 > ny || ny >= c) continue;
            if(visited[nx][ny] || ground[nx][ny]=='#') continue;
            visited[nx][ny] = 1;
            if(ground[nx][ny] == 'o') s++;
            if(ground[nx][ny] == 'v') w++;
            q.push({nx,ny});
        }
    }
    //if 曄 熱 > 期渠 熱 期渠 賅舒 薯剪
    if(s > w) wolfCnt -= w;
    else sheepCnt -= s;
}

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++) cin >> ground[i];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(ground[i][j] =='o') sheepCnt++;
            if(ground[i][j] =='v') wolfCnt++;
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(ground[i][j]!='#' && !visited[i][j]){
                bfs(i,j);
            }
        }
    }
    
    cout << sheepCnt << ' ' << wolfCnt <<'\n';
}