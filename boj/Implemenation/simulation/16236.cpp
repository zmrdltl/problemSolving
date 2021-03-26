#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int,int>;
using ttup = tuple<int,int,int>;
struct sharkInfo { int x, y, size, eat; };
sharkInfo babyShark;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int space[21][21];
int visited[21][21];
int dist[21][21];
int n, time;

int eatFish(){
    memset(dist,0,sizeof(dist));
    memset(visited,0,sizeof(visited));
    queue <pii> q;
    vector <ttup> eatableFish;
    q.push({babyShark.x,babyShark.y});
    visited[babyShark.x][babyShark.y] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= n || 0 > ny || ny >= n) continue;
            if(visited[nx][ny] || space[nx][ny] > babyShark.size) continue;
            visited[nx][ny] = 1;
            q.push({nx,ny});
            dist[nx][ny] = dist[x][y] + 1;
            //먹을 수 있는 물고기 좌표 탐색
            if(space[nx][ny] && space[nx][ny] < babyShark.size){
                eatableFish.push_back({dist[nx][ny],nx,ny});
            }
        }
    }
    
    if(!eatableFish.size()) return 0;

    sort(eatableFish.begin(),eatableFish.end());
    
    int d = get<0>(eatableFish[0]);
    int x = get<1>(eatableFish[0]);
    int y = get<2>(eatableFish[0]);

    time += d;
    space[babyShark.x][babyShark.y] = 0; //기존 아기상어 정보 삭제
    babyShark.x = x;
    babyShark.y = y;
    babyShark.eat++;
    space[x][y] = 0;

    if(babyShark.eat == babyShark.size) {
        babyShark.size++;
        babyShark.eat = 0;
    }
    return 1;

}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> space[i][j];
            if(space[i][j] == 9) babyShark = {i,j,2,0};
        }
    }
    while(eatFish());
    cout << time << '\n';
}