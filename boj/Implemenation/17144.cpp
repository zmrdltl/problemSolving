#include <bits/stdc++.h>
using namespace std;
int r,c,t;
int room[51][51];
int dir[51][51];
int copyRoom[51][51];
//상 우 하 좌
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

struct coords{
    int x1,y1;
};

vector <coords> airCleaner;

//방향 정하기
void setDir(){
    //가장 위,아래의 방향 : 좌
    for(int i = 0; i < c; i++){
        dir[0][i] = 3;
        dir[r-1][i] = 3;
    }

    //공기 청정기 정면 : 우
    for(auto &a : airCleaner){
        for(int i = 0; i < c; i++){
            dir[a.x1][i] = 1;
        }
    }

    //공기 청정기 머리에서 정면 끝 : 상
    for(int i = 1; i <= airCleaner[0].x1; i++){
        dir[i][c-1] = 0;
    }

    //공기 청정기 다리에서 정면 끝 : 하
    for(int i = airCleaner[1].x1; i < r - 1; i++){
        dir[i][c-1] = 2;
    }

    for(int i = 0; i < airCleaner[0].x1; i++){
        dir[i][0] = 2;
    }

    for(int i = airCleaner[1].x1 + 1; i < r; i++){
        dir[i][0] = 0;
    }
}

//확산
void spread(){
    int margin[51][51] ={0};
    int spreadWays[51][51] = {0};
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(room[i][j]==-1 || !room[i][j]) continue;
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                int nr = i + dx[k];
                int nc = j + dy[k];
                if(0 > nr || nr >= r || 0 > nc || nc >= c) continue;
                if(room[nr][nc]==-1) continue;
                margin[nr][nc] += room[i][j]/5;
                cnt++;
            }
            spreadWays[i][j] = cnt;
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            room[i][j] = room[i][j] -  room[i][j]/5*spreadWays[i][j] + margin[i][j];
        }
    }
}

//공기 청정기 작동 , 바람 방향 따라 먼지 이동
void operateAirCleaner(){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(room[i][j] == -1) continue;
            if(!dir[i][j] && j != 0 && j != c-1) {
                copyRoom[i][j] = room[i][j];
                continue;
            }
            int nx = i + dx[dir[i][j]];
            int ny = j + dy[dir[i][j]];
            if(room[nx][ny] == -1) continue;
            copyRoom[nx][ny] = room[i][j];
        }
    }
   
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(room[i][j] == -1) continue;
            room[i][j] = copyRoom[i][j];
        }
    }
}

int getDustAmount(){
    int amount = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(room[i][j] == -1) continue;
            amount +=room[i][j];
        }
    }
    return amount;
}

int main(){
    cin >> r >> c >> t;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> room[i][j];
            if(room[i][j] == -1) airCleaner.push_back({i,j});
        }
    }
    setDir();
    while(t--){
        spread();
        operateAirCleaner();
    }
    cout << getDustAmount();
}

