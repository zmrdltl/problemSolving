#include <bits/stdc++.h>
using namespace std;
int board[101][101];

//╩С,©Л,го,аб
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int n,k,l,sec,flag,direction = 1;

struct Snake {int x,y;};

deque <Snake> snake;
map <int,char> m;

int main(){
    snake.push_back({1,1});
    cin >> n >> k;

    while(k--){
        int x,y;
        cin >> x >> y;
        board[x][y] = 1;
    }
    cin >> l;

    while(l--){
        int x;
        char dir;
        cin >> x >> dir;
        m[x] = dir;
    }

    while(1){
        sec++;
        int x = snake.front().x;
        int y = snake.front().y;
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        for(auto &el : snake)
            if(el.x == nx && el.y == ny) 
                { flag = 1; break; }
        if(1 > nx || nx > n || 1 > ny || ny > n || flag) { flag = 1; break; }
        snake.push_front({nx,ny});
        if(!board[nx][ny]){ snake.pop_back();}
        else board[nx][ny] = 0;
        if(m[sec] == 'D') direction = (direction + 1) % 4;
        else if(m[sec] == 'L') direction = (3 + direction) % 4;
    }

    cout << sec << '\n';
}