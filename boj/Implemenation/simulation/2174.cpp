#include <bits/stdc++.h>
using namespace std;
int board[101][101];
//ºÏ, µ¿, ³², ¼­
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int b,a,n,m;
struct Robot{ int x,y,dir; };
vector <Robot> robot;
string ans;

void moveRobot(int robotNum, int iter, char op){
    if(ans!="") return;

    for(int i = 0; i < iter; i++){
        int DIR = robot[robotNum].dir;
        int X = robot[robotNum].x;
        int Y = robot[robotNum].y;
        if(op == 'L'){
            robot[robotNum].dir = (4 + DIR - 1 ) % 4;
        }
        else if(op == 'R'){
            robot[robotNum].dir = (DIR + 1) % 4;
        }
        else if(op == 'F'){
            int nx = X + dx[DIR];
            int ny = Y + dy[DIR];
            if(1 > nx || nx > b || 1 > ny || ny > a){
                ans = "Robot " + to_string(robotNum+1) + " crashes into the wall";
                break;
            }
            if(board[nx][ny]){
                ans = "Robot " + to_string(robotNum+1) + " crashes into robot " + to_string(board[nx][ny]);
                break;
            }
            board[X][Y] = 0;
            robot[robotNum].x = nx;
            robot[robotNum].y = ny;
            board[nx][ny] = robotNum + 1;
        }
    }
}

int main(){
    cin >> a >> b >> n >> m;
    for(int i = 0; i < n; i++){
        int x,y,dir;
        char d;
        cin >> x >> y >> d;
        if(d == 'N') dir = 0;
        else if(d == 'E') dir = 1;
        else if(d == 'S') dir = 2;
        else if(d == 'W') dir = 3;
        robot.push_back({b-y+1,x,dir});
        board[b-y+1][x] = i + 1;
    }

    while(m--){
        int robotNum, iter;
        char op;
        cin >> robotNum;
        cin >> op;
        cin >> iter;
        moveRobot(robotNum-1, iter, op);
    }

    if(ans == "") cout << "OK";
    else cout << ans;
}