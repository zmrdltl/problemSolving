#include <bits/stdc++.h>
using namespace std;
int n,m;
int board[11][11];
int ck[11][11];
//북 동 남 서
int dx[] = {-1, 0, 1,0};
int dy[] = {0, 1, 0,-1};
int area[51][51];
int visited[51][51];
int ans;
struct robotInfo{
    int row, col, curDir;
};
robotInfo robot;
void dfs(int row, int col, int curDir, int curCnt){
    if(curCnt>=4){
        int x = row - dx[curDir];
        int y = col - dy[curDir];
        if(0 > x || x >= n || 0 > y || y >= m || area[x][y] != 2) return; 
        dfs(x,y,curDir,0);
        return;
    }
    area[row][col] = 2;
    int newDir = ((curDir-1) + 4) % 4; //왼쪽으로 틀기
    int nx = row + dx[newDir];
    int ny = col + dy[newDir];
    if(0 > nx || nx >= n || 0 > ny || ny >= m) return;
    if(area[nx][ny] == 0) dfs(nx,ny,newDir,0);
    else dfs(row,col,newDir,curCnt+1);
}

int main(){
    cin >> n >> m;
    cin >> robot.row >> robot.col >> robot.curDir;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> area[i][j];
        }
    }
    dfs(robot.row,robot.col,robot.curDir,0);
    for(int i =0 ;i <n; i++){
        for(int j = 0 ;j <m;j++){
            if(area[i][j]==2) ans++;
        }
    }
    cout << ans <<'\n';
}