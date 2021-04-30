#include <bits/stdc++.h>
using namespace std;
int n,m;
int dx[] = {0, 1, 1, 1, 0, 0, 0, -1, -1,-1};
int dy[] = {0,-1, 0, 1,-1, 0, 1, -1,  0, 1};
string moveInfo;
struct Jongsu {int x, y;};
Jongsu jongsu;
char board[101][101];
map <pair<int,int>,int> arduino;

int moveJongsu(int dir, int move){
    board[jongsu.x][jongsu.y] = '.';
    jongsu.x += dx[dir];
    jongsu.y += dy[dir];
    if(board[jongsu.x][jongsu.y] != '.') return move;
    board[jongsu.x][jongsu.y] = 'I';
    return 0;
}

int moveArduino(int move){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'R'){
                int moveDir = 0;
                int minDist = 0x3f3f3f3f;
                for(int dir = 1; dir <= 9; dir++){
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
                    int dist = abs(nx - jongsu.x) + abs(ny - jongsu.y);
                    if(minDist > dist){
                        moveDir = dir;
                        minDist = dist;
                    }
                }
                int nx = i + dx[moveDir];  
                int ny = j + dy[moveDir];
                if(board[nx][ny] == 'I') return move;
                if(arduino[{i,j}]) arduino[{i,j}]--;
                arduino[{nx,ny}]++;
            }
        }
    }
    
    return 0;
}

void boom(){
    vector <pair<int,int>> v;
    for(auto &a : arduino){
        if(a.second != 1) v.push_back(a.first);
    }
    for(auto &p : v){
        arduino.erase(p);
    }
}

void updateBoard(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            board[i][j] = '.';
        }
    }
    board[jongsu.x][jongsu.y] = 'I';
    for(auto &a : arduino){
        pair <int,int> p = a.first;
        board[p.first][p.second] = 'R';
    }
}

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 'I') jongsu.x = i, jongsu.y = j;
            if(board[i][j] == 'R') arduino[{i,j}] = 1;
        }
    }

    cin >> moveInfo;

    for(int i = 0; i < moveInfo.size(); i++){
        int dir = moveInfo[i] - '0';
        int move = 0;
        move = max(move,moveJongsu(dir,i+1));
        move = max(move,moveArduino(i + 1));
        if(move){
            cout << "kraj " << move << '\n';
            return 0;
        }
        boom();
        updateBoard();
        
    }
    print();
}