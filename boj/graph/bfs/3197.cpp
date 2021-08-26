#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int r, c, ck[1501][1501], timer;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char lake[1501][1501];

struct Swan {int r,c; };
vector <Swan> swan;
queue <pii> swanQ, waterQ;

void meltIce(){
    int wSize = waterQ.size();
    while(wSize--){
        int x = waterQ.front().first;
        int y = waterQ.front().second;
        waterQ.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= r || 0 > ny || ny >=c) continue;
            if(lake[nx][ny] != 'X') continue;
            waterQ.push({nx,ny});
            lake[nx][ny] = '.';
        }
    }
}

bool canMeet(){
    queue <pii> s;
    while(!swanQ.empty()){
        int x = swanQ.front().first;
        int y = swanQ.front().second;
        swanQ.pop();
        if(x == swan[1].r && y == swan[1].c) return true;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= r || 0 > ny || ny >= c) continue;
            if(ck[nx][ny]) continue;
            if(lake[nx][ny] == 'X') s.push({nx,ny}); //다음날에 다닐수 있다.
            else swanQ.push({nx,ny});
            ck[nx][ny] = 1;
        }
    }
    swanQ = s;
    return false;
}

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++) {
            cin >> lake[i][j];
            if(lake[i][j] == 'L') waterQ.push({i,j}),swan.push_back({i,j});
            if(lake[i][j] == '.') waterQ.push({i,j});
        }
    }
    swanQ.push({swan[0].r,swan[0].c});
    while(1){
        if(canMeet()) break;
        meltIce();
        timer++;
    }
    cout << timer;
}