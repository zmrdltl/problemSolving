#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n,m, ans;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int map[101][101];
int checkAir[101][101];
int checkCheese[101][101];

queue <pair<int,int>> cheese,air;

void meltCheese() {
    while (!cheese.empty()) {
        int x = cheese.front().first; 
        int y = cheese.front().second;
        cheese.pop();
        checkCheese[x][y]++;

        if (checkCheese[x][y] == 2) {
            map[x][y] = 0;
        }
    }
}

bool isAllMelt(){
    for(int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j]) return 0;
        }
    }
    return 1;
}

void bfs() {
    air.push({0,0});
    checkAir[0][0] = 1;
    while (!air.empty()) {
        int x = air.front().first;
        int y = air.front().second;

        air.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 > nx || nx >= n || 0 > ny || ny >= m) continue;
            if (checkAir[nx][ny])continue;
            //치즈라면
            if (map[nx][ny]) {
                cheese.push({ nx,ny });
                continue;
            }
            //외부공기라면
            checkAir[nx][ny] = true;
            air.push({ nx,ny });
        }
    }
}


int main(){
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    while(!isAllMelt()){
        ans++;
        memset(checkCheese,0,sizeof(checkCheese));
        memset(checkAir,0,sizeof(checkAir));
        bfs();
        meltCheese();
    }
    cout << ans <<'\n';
    
}