#include <bits/stdc++.h>
using namespace std;
int n, m, r, score;
int board[101][101];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char isFell[101][101];

int getDirection(char d){
    if(d == 'E') return 0;
    if(d == 'W') return 1;
    if(d == 'S') return 2;
    return 3;
}

void fallDownDomino(int startRow, int startCol, int dir) {
    int height = board[startRow][startCol];
    int nx = startRow;
    int ny = startCol;
    while(height){
        if(1 > nx || nx > n || 1 > ny || ny > m) break;
        if(isFell[nx][ny] == 'S'){
            isFell[nx][ny] = 'F';
            score++;
            height = max(height,board[nx][ny]);
        }
        nx += dx[dir];
        ny += dy[dir];
        height--;
    }
}

void print(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << isFell[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){

    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> board[i][j];
            isFell[i][j] = 'S';
        }
    }

    while(r--){
        int offenseX,offenseY,defenseX,defenseY;
        char d;
        cin >> offenseX >> offenseY >> d;
        cin >> defenseX >> defenseY;
        int dir = getDirection(d);
        if(isFell[offenseX][offenseY] == 'S') fallDownDomino(offenseX, offenseY, dir);
        isFell[defenseX][defenseY] = 'S';
    }

    cout << score << '\n';
    print();
}   