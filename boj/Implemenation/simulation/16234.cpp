#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n,l,r,cnt;
int population[51][51];
int checkOpen[51][51];
int visited[51][51];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool haveToMove(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(checkOpen[i][j]) return true;
        }
    }
    return false;
}

void movePopulation(int i,int j){
    queue <pii> q;
    queue <pii> moveQ;
    int area = 1;
    int areaNum = checkOpen[i][j];
    int totalPopulation = population[i][j];
    visited[i][j] = 1;
    q.push({i,j});
    moveQ.push({i,j});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= n || 0 > ny || ny >= n) continue;
            if(checkOpen[nx][ny] != areaNum || !checkOpen[nx][ny] || visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            area++;
            totalPopulation += population[nx][ny];
            q.push({nx,ny});
            moveQ.push({nx,ny});
        }
    }

    int afterMovedPeopleNum = totalPopulation / area;
    while(!moveQ.empty()){
        int x = moveQ.front().first;
        int y = moveQ.front().second;
        moveQ.pop();
        population[x][y] = afterMovedPeopleNum;
    }
}

void stepOne(){
    memset(checkOpen,0,sizeof(checkOpen));
    memset(visited,0,sizeof(visited));
    queue <pii> q;
    int areaNum = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j]) continue;
            areaNum++;
            visited[i][j] = 1;
            q.push({i,j});
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k = 0; k < 4; k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(0 > nx || nx >= n || 0 > ny || ny >= n) continue;
                    if(visited[nx][ny]) continue;
                    int diff = abs(population[x][y] - population[nx][ny]);
                    if(l > diff || diff > r) continue;
                    visited[nx][ny] = 1;
                    checkOpen[x][y] = checkOpen[nx][ny] = areaNum;
                    q.push({nx,ny});
                }
            }
        }
    }
}

void stepTwo(){
    memset(visited,0,sizeof(visited));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!checkOpen[i][j] || visited[i][j]) continue;
            movePopulation(i,j);
        }
    }
    cnt++;
}

int main(){
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> population[i][j];
        }
    }

    while(1){
        stepOne(); //열 국경 check하기
        if(!haveToMove()) break;
        stepTwo(); //연합 국경 인구 이동.
    }
    cout << cnt << '\n';
}