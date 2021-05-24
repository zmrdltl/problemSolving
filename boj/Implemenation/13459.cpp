#include <bits/stdc++.h>
using namespace std;
int n, m, escapeRow, escapeCol;
char board[11][11];
char boardCopy[11][11];
int ballsCk[11][11][11][11];
int ballsDist[11][11][11][11];
int redBallRow, redBallCol, blueBallRow, blueBallCol;
//╩С ©Л го аб
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};


void copyBoard(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            boardCopy[i][j] = board[i][j];
        }
    }
}

void bfs(){
    
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> board[i][j];
            if(board[i][j] == 'R') redBallRow = i, redBallCol = j;
            if(board[i][j] == 'B') blueBallRow = i, blueBallCol = j;
            boardCopy[i][j] = board[i][j];
        }
    }


}