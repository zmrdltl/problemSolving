#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n, m, board[21][21], ck[21][21], points;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

struct blockInfo {int area,rainbowBlock,standardX,standardY;};
//기준블록, 블록 영역 개수
vector <blockInfo> groups;

bool cmp(blockInfo a, blockInfo b){
    if(a.area == b.area){
        if(a.rainbowBlock == b.rainbowBlock){
            if(a.standardX == b.standardX) return a.standardY > b.standardY;
            return a.standardX > b.standardX;
        }
        return a.rainbowBlock > b.rainbowBlock;
    }
    return a.area > b.area;
}

void releaseRainBowBlock(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!board[i][j]) ck[i][j] = 0;
        }
    }
}
void findBlockGroup(){
    queue <pii> q;
    memset(ck,0,sizeof(ck));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            releaseRainBowBlock();
            //없어진곳, 검, 무지개는 안봄
            if(board[i][j] < 0 || !board[i][j] || ck[i][j]) continue;
            //i,j는 기준 블록
            q.push({i,j});
            int area = 1;
            int rainbowBlock = 0;
            ck[i][j] = 1;
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(0 > nx || nx >= n || 0 > ny || ny >= n) continue;
                    if(board[nx][ny] != board[i][j] && board[nx][ny] || ck[nx][ny]) continue;
                    if(!board[nx][ny]) rainbowBlock++;
                    ck[nx][ny] = 1;
                    q.push({nx,ny});
                    area++;
                }
            }
            if(area >= 2) groups.push_back({area,rainbowBlock,i,j});
        }
    }
}

void removeMaxBlockGroup(){
    sort(groups.begin(),groups.end(),cmp);
    memset(ck,0,sizeof(ck));
    int originX = groups[0].standardX;
    int originY = groups[0].standardY;
    queue <pii> q;
    queue <pii> removeQ;

    q.push({originX,originY});
    ck[originX][originY] = 1;
    removeQ.push({originX,originY});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(0 > nx || nx >= n || 0 > ny || ny >= n) continue;
            if(board[nx][ny] != board[originX][originY] && board[nx][ny] || ck[nx][ny]) continue;
            ck[nx][ny] = 1;
            q.push({nx,ny});
            removeQ.push({nx,ny});
        }
    }
    while(!removeQ.empty()){
        int x = removeQ.front().first;
        int y = removeQ.front().second;
        removeQ.pop();
        board[x][y] = -2;
    }
    points += groups[0].area * groups[0].area;
}

void rotateBoard(){
    int tmp[21][21];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            tmp[i][j] = board[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board[i][j] = tmp[j][n-i-1];
}

void gravity(){
    for(int i = 0; i < n; i++){
        queue <int> block; //행
        queue <int> blackBlock; //행
        for(int j = n-1; j >= 0; j--){
            if(board[j][i] >= -1) block.push(board[j][i]);
            if(board[j][i] == -1) blackBlock.push(j);
        }

        if(!block.size()) continue;

        for(int j = n-1; j >= 0; j--) board[j][i] = -2;

        for(int j = n-1; j >= 0; j--){
            if(!block.size()) break;
            int val = block.front();
            block.pop();
            if(val == -1){
                int blackRow = blackBlock.front();
                blackBlock.pop();
                board[blackRow][i] = -1;
                j = blackRow;
            }
            else board[j][i] = val;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
            
    while(1){
        groups.clear();
        findBlockGroup();
        if(!groups.size()) break;
        removeMaxBlockGroup();
        gravity();
        rotateBoard();
        gravity();
    }
    cout << points << '\n';
}
