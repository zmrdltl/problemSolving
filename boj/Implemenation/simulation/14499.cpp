#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
//À§,¾Æ·¡,µ¿,¼­,³²,ºÏ
vector <int> dice = {0,0,0,0,0,0};
int n,m,x,y,k;
int board[21][21];

//µ¿,¼­,ºÏ,³²
int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};

void rollDice(int dir){
    vector <int> tmp(6);
    //µ¿
    if(dir == 1){
        tmp[5] = dice[5];
        tmp[4] = dice[4];
        tmp[3] = dice[1];
        tmp[2] = dice[0];
        tmp[1] = dice[2];
        tmp[0] = dice[3];
    }
    //¼­
    else if(dir == 2){
        tmp[5] = dice[5];
        tmp[4] = dice[4];
        tmp[3] = dice[0];
        tmp[2] = dice[1];
        tmp[1] = dice[3];
        tmp[0] = dice[2];
    }
    //ºÏ
    else if(dir == 3){
        tmp[5] = dice[0];
        tmp[4] = dice[1];
        tmp[3] = dice[3];
        tmp[2] = dice[2];
        tmp[1] = dice[5];
        tmp[0] = dice[4];
    }
    //³²
    else if(dir == 4){
        tmp[5] = dice[1];
        tmp[4] = dice[0];
        tmp[3] = dice[3];
        tmp[2] = dice[2];
        tmp[1] = dice[4];
        tmp[0] = dice[5];
    }
    dice = tmp;
}

void updateBoard(int r, int c){
    if(!board[r][c]) board[r][c] = dice[1];
    else dice[1] = board[r][c], board[r][c] = 0;
}

int main(){
    fastio;
    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    while(k--){
        int dir;
        cin >> dir;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;

        rollDice(dir);
        updateBoard(nx, ny);
        cout << dice[0] << '\n';
        x = nx, y = ny;
    }
}