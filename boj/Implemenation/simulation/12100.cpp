#include <bits/stdc++.h>
using namespace std;
using pii = pair <int,int>;
//이동 중 이미 합쳐진 블록은 바로 또 합칠 수 없다
int n, ans;
int board[21][21];
int boardCopy[21][21];
int stat[5];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
//dir = 0 : 상, 1 : 우, 2 : 하, 3 : 좌로 이동
void moveBlock(int dir){
    queue <pii> q;
    int isCombined[21][21];
    memset(isCombined,0,sizeof(isCombined));
    if(dir == 0){
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                if(boardCopy[i][j] == boardCopy[i-1][j] && !isCombined[i-1][j]){
                    isCombined[i-1][j] = 1;
                    q.push({boardCopy[i-1][j] + boardCopy[i][j],j});
                    boardCopy[i-1][j] = 0;
                    boardCopy[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            int val = q.front().first;
            int col = q.front().second;
            for()
        }
    }
}

void copyBoard(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            boardCopy[i][j] = board[i][j];
        }
    }
}

int getMaxBlock(){
    int big = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            big = max(big,boardCopy[i][j]);
    return big;
}

void printBoardCopy(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << boardCopy[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

int main(){
    cin >> n;
    //5번 이동으로 최소
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    //각 이동 방향은 0,1,2,3으로 표현됨
    //i번째 이동의 이동 방향은 1 2 1 2 1 이런식으로 표현
    //i번째 이동 방향 구하고 이동하기

    for(int i = 0; i < 4; i++){
        copyBoard();
        moveBlock(i);
        printBoardCopy();
    }
    // for(int movedStat = 0; movedStat < 1 << (2 * 5); movedStat++){
    //     copyBoard();
    //     for(int j = 0; j < 5; j++){

    //     }

    // }
}