#include <iostream>
#include <algorithm>
using namespace std;
using pii = pair<int,int>;
char map[11][11];
char ans[11][11];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int r,c;

int getLastYidx(){
    int idx = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(ans[i][j] == 'X') idx = max(idx,i);
        }
    }
    return idx;
}

pii getLastXidx(){
    int idxX = 0;
    int idxY = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(ans[i][j] == 'X') idxX = max(idxX,i), idxY = max(idxY,j);
        }
    }
    return {idxX,idxY};
}

pii getFirstXidx(){
    int idxX = 1000;
    int idxY = 1000;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(ans[i][j] == 'X') idxX = min(idxX,i), idxY = min(idxY,j);
        }
    }
    return {idxX,idxY};
}

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++)
            cin >> map[i];

    for(int i = 0; i < r; i++){
        for(int j = 0 ; j < c; j++){
            if(map[i][j] != 'X') continue;
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x < 0 || x >= r || y < 0 || y >= c) {cnt++; continue;}
                if(map[x][y] == '.') cnt++;
            }
            if(cnt >= 3) map[i][j] = ' ';
        }
    }
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++){
            if(map[i][j] == 'X') ans[i][j] = map[i][j];
        }
    }

    pii firstIdx = getFirstXidx();
    pii lastIdx = getLastXidx();

    for(int i = firstIdx.first; i <= lastIdx.first; i++) {
        for(int j = firstIdx.second; j <= lastIdx.second; j++){
            if(ans[i][j] != 'X') cout << '.';
            else cout << ans[i][j];
        }
        cout << '\n';
    }
}