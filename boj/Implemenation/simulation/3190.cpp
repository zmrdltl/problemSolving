#include <bits/stdc++.h>
using namespace std;
int board[101][101];

//╩С,©Л,го,аб
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int n,k,l,ans,flag,direction = 1;

struct Snake {int x,y;};
struct Info {int x, dir;};

deque <Snake> snake;
queue <Info> q;

void goSnake(int start, int end){
    for(int time = start; time <= end; time++){
        ans++;
        int x = snake.front().x;
        int y = snake.front().y;
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        for(auto &el : snake){
            if(el.x == nx && el.y == ny) { flag = 1; break;}
        }
        if(1 > nx || nx > n || 1 > ny || ny > n || flag){ flag = 1; break; }
        snake.push_front({nx,ny});
        if(!board[nx][ny]){ snake.pop_back();}
        else board[nx][ny] = 0;
    }
}

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
        q.push({x,dir});
    }

    while(!q.empty()){
        int x = q.front().x;
        int dir = q.front().dir;
        goSnake(ans + 1, x);
        if(flag) break;
        ans = x;
        if(dir == 'D') direction = (direction + 1) % 4;
        else direction = (3 + direction) % 4;
        q.pop();
    }
    if(!flag){ goSnake(ans,20000); }
    cout << ans << '\n';
}