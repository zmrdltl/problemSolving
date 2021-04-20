#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
int oddEvenDir[] = {0,2,4,6};
int elseDir[] = {1,3,5,7};
struct info{ int x, y, weight, speed, dir; };

vector <info> fireBalls;
vector <info> board[51][51];

void moveBalls(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) 
            board[i][j].clear();

    for(int i = 0; i < fireBalls.size(); i++){
        int x = fireBalls[i].x;
        int y = fireBalls[i].y;
        int weight = fireBalls[i].weight;
        int speed = fireBalls[i].speed;
        int dir = fireBalls[i].dir;
        int move = speed % n;

        int nx = x + dx[dir] * move;
        int ny = y + dy[dir] * move;
        if (nx > n) nx -= n;
        if (ny > n) ny -= n;
        if (nx < 1) nx += n;
        if (ny < 1) ny += n;
        fireBalls[i].x = nx;
        fireBalls[i].y = ny;
        board[nx][ny].push_back({ nx,ny,weight,speed,dir });
    }
}

void sumAndDivBalls(){
    vector<info> tmp;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (board[i][j].size() == 0) continue;
            if (board[i][j].size() == 1){
                tmp.push_back(board[i][j][0]);
                continue;
            }
            
            int weightSum = 0;
            int speedSum = 0;
            int ballsCnt = board[i][j].size();
 
            bool isEven = true;
            bool isOdd = true;
            
            for (int k = 0; k < board[i][j].size(); k++){
                weightSum += board[i][j][k].weight;
                speedSum += board[i][j][k].speed;
                if (board[i][j][k].dir % 2 == 0) isOdd = false;
                else isEven = false;
            }
            
            int mass = weightSum / 5;
            int speed = speedSum / ballsCnt;
            if (!mass) continue;
            if (isEven == true || isOdd == true){
                for (int k = 0; k < 4; k++) tmp.push_back({ i, j, mass, speed, oddEvenDir[k] });
            }
            else{
                for (int k = 0; k < 4; k++) tmp.push_back({ i, j, mass, speed, elseDir[k] });
            }
        }
    }
    fireBalls = tmp;
}


int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int r,c,m,s,d;
        cin >> r >> c >> m >> s >> d;
        fireBalls.push_back({r,c,m,s,d});
        board[r][c].push_back({r,c,m,s,d});
    }

    while(k--){
        moveBalls();
        sumAndDivBalls();
    }

    for(int i = 0; i < fireBalls.size(); i++) ans += fireBalls[i].weight;
    cout << ans <<'\n';
}