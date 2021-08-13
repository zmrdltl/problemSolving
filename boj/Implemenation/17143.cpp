#include <bits/stdc++.h>
using namespace std;
int r, c, m, catchCnt;
struct Shark {int r, c, sp, d, sz, num; };
struct King {int r = 1, c = 0; } fishKing;
vector <Shark> board[101][101], shark;
// x, 상, 하, 우, 좌
int dr[] = {0,-1,1,0,0};
int dc[] = {0,0,0,1,-1};

bool cmp(Shark &a, Shark &b){
    return a.sz > b.sz; 
}

void moveFishKing(){
    fishKing.c++;
}

void updateStatus(){
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            board[i][j].clear();
            
    for(auto &s : shark) board[s.r][s.c].push_back(s);
    shark.clear();

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(!board[i][j].size()) continue;
            sort(board[i][j].begin(),board[i][j].end(),cmp);
            Shark biggestShark = board[i][j][0];
            board[i][j].clear();
            board[i][j].push_back(biggestShark);
            shark.push_back(biggestShark);
        }
    }
}


void catchClosestShark(){
    int sharkNum = -1;
    for(int i = 1; i <= r; i++){
        if(board[i][fishKing.c].size()){
            catchCnt += board[i][fishKing.c][0].sz;
            sharkNum = board[i][fishKing.c][0].num;
            board[i][fishKing.c].clear();
            break;
        }
    }

    if(sharkNum >= 0){
        for(auto s = shark.begin(); s != shark.end(); s++)
            if(s->num == sharkNum) { shark.erase(s); break; }
    }
}

void moveShark(){
    for(auto &s : shark){
        int nr = s.r;
        int nc = s.c;
        int iterRow = abs(dr[s.d] * s.sp);
        int iterCol = abs(dc[s.d] * s.sp);
        //위아래 초과
        for(int i = 0; i < iterRow; i++){
            if(nr == 1 && s.d == 1) s.d = 2;
            if(nr == r && s.d == 2) s.d = 1;
            nr += dr[s.d];
        }
        //좌우초과시 방향전환
        for(int i = 0; i < iterCol; i++){
            if(nc == 1 && s.d == 4) s.d = 3;
            if(nc == c && s.d == 3) s.d = 4;
            nc += dc[s.d];
        }
        s.r = nr;
        s.c = nc;
    }
}

int main(){
    cin >> r >> c >> m;
    shark.resize(m);
    for(int i = 0; i < m; i++){
        int r,c,s,d,z;
        cin >> r >> c >> s >> d >> z;
        shark[i] = {r,c,s,d,z,i};
        board[r][c].push_back(shark[i]);
    }

    for(int i = 1; i <= c; i++){
        moveFishKing();
        catchClosestShark();
        moveShark();
        updateStatus();
    }
    
    cout << catchCnt;
}