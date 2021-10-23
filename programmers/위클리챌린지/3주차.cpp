#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
struct Coord {int r, c; };
vvi gameBoard, table;
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};
int emptyBlock[51][51], block[51][51],n;

void refineBlock(){
    deque <Coord> dq;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(block[i][j]) dq.push_back({i,j}), block[i][j] = 0;
        }
    }

    int minR = 0x3f3f3f3f;
    int minC = 0x3f3f3f3f;
    queue <Coord> tmpQ;

    for(auto d : dq){
        minR = min(minR, d.r);
        minC = min(minC, d.c);
        tmpQ.push(d);
    }

    for(auto &d : dq) d.r -= minR, d.c -= minC;
    for(auto d : dq) block[d.r][d.c] = 1;
}

void rotateBlock(){
    int tmp[51][51] = {0};
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            tmp[i][j] = block[n-j-1][i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            block[i][j] = tmp[i][j];
}

bool isSame(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(block[i][j] != emptyBlock[i][j]) 
                return false;
    return true;
}

int bfs(int i, int j, int ck[51][51], int option){
    if(!option) memset(emptyBlock,0,sizeof(emptyBlock));
    else memset(block,0,sizeof(block));
    deque <Coord> dq;
    queue <Coord> tmpQ;
    ck[i][j] = 1;
    tmpQ.push({i,j});
    dq.push_front({i,j});
    int area = 1;
    while(!tmpQ.empty()){
        int r = tmpQ.front().r;
        int c = tmpQ.front().c;
        tmpQ.pop();
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(0 > nr || nr >= n || 0 > nc || nc >= n) continue;
            if(!option && gameBoard[nr][nc] || ck[nr][nc]) continue;
            if(option && !table[nr][nc] || ck[nr][nc]) continue;
            ck[nr][nc] = 1;
            dq.push_front({nr,nc});
            tmpQ.push({nr,nc});
            area++;
        }
    }
    
    int minR = 0x3f3f3f3f;
    int minC = 0x3f3f3f3f;

    for(auto d : dq){
        minR = min(minR, d.r);
        minC = min(minC, d.c);
        tmpQ.push(d);
    }
    for(auto &d : dq) d.r -= minR, d.c -= minC;

    if(!option)
        for(auto d : dq)
            emptyBlock[d.r][d.c] = 1;

    else
        for(auto d : dq)
            block[d.r][d.c] = 1;
    
    return area;
}

void delBFS(int i, int j){
    queue <Coord> q;
    q.push({i,j});
    int ck[51][51] = {0};
    ck[i][j] = 1;
    table[i][j] = 0;
    while(!q.empty()){
        int r = q.front().r;
        int c = q.front().c;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(0 > nr || nr >= n || 0 > nc || nc >= n) continue;
            if(ck[nr][nc] || !table[nr][nc]) continue;
            ck[nr][nc] = 1;
            q.push({nr,nc});
            table[nr][nc] = 0;
        }
    }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> t) {
    gameBoard = game_board;
    table = t;
    int ck[51][51] = {0};
    int ck2[51][51] = {0};
    int answer = 0;
    n = gameBoard.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ck[i][j] || gameBoard[i][j]) continue;
            
            int area = bfs(i,j,ck,0);
            memset(ck2,0,sizeof(ck2));
            for(int r = 0; r < n; r++){
                for(int c = 0; c < n; c++){
                    if(ck2[r][c] || !table[r][c]) continue;
                    int area2 = bfs(r,c,ck2,1);

                    for(int rot = 0; rot < 4; rot++){
                        if(isSame()){
                            delBFS(r,c);
                            goto SUCCESS;
                        }
                        rotateBlock();
                        refineBlock();
                    }
                }
            }
            continue;
            SUCCESS :
                answer += area;
        }
    }
    return answer;
}