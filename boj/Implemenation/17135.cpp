#include <bits/stdc++.h>
using namespace std;
int n, m, d, ans, killedEnemy;

int boardCopy[20][20],board[20][20], ck[20][20], dist[20][20], killCk[20][20];

void getDistanceFrom(int arcNum){
    memset(dist,0,sizeof(dist));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!boardCopy[i][j]) continue;
            dist[i][j] = abs(n+1 - i) + abs(arcNum - j);
        }
    }
}

void killCheck(){
    int minDist = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(dist[i][j] > d || !dist[i][j]) continue;
            minDist = min(minDist,dist[i][j]);
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = n; j >= 1; j--){
            if(minDist == dist[j][i] ){
                killCk[j][i] = 1;
                return;
            }
        }
    }
}

void goDown(){
    for(int i = 1; i <= m; i++){
        for(int j = n; j >= 1; j--){
            if(!boardCopy[j][i]) continue;
            if(j==n) boardCopy[j][i] = 0;
            else{
                boardCopy[j][i] = 0;
                boardCopy[j+1][i] = 1;
            }
        }
    }
}

bool enemyExist(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(boardCopy[i][j]) return 1;
        }
    }
    return 0;
}

void copyBoard(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            boardCopy[i][j] = board[i][j];
        }
    }
}

void killEnemy(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(killCk[i][j]) {
                killedEnemy++;
                boardCopy[i][j] = 0;
            }
        }
    }
}

void dfs(int depth, int idx){
    if(depth==3){
        killedEnemy = 0;
        copyBoard();
        while(enemyExist()){
            memset(killCk,0,sizeof(killCk));

            for(int arcNum = 1; arcNum <= m; arcNum++) {
                if(!boardCopy[n+1][arcNum]) continue;
                getDistanceFrom(arcNum);
                killCheck();
            }
            killEnemy();
            goDown();
            ans = max(ans,killedEnemy);
        }
        return;
    }

    for(int i = idx; i <= m; i++){
        if(ck[n+1][i]) continue;
        ck[n+1][i] = 1;
        boardCopy[n+1][i] = 1;
        dfs(depth+1, i+1);
        boardCopy[n+1][i] = 0;
        ck[n+1][i] = 0;
    }
}

int main(){
    cin >> n >> m >> d;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> board[i][j];
        }
    }
    dfs(0,1);
    cout << ans << '\n';
}