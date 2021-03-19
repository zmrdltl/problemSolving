//TODO
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int visited[1001][1001];
int fireVisited[1001][1001];
string building[1001];
int distance[1001][1001];
int w,h,t;

void fireBFS(int i, int j){
    queue <pii> fq;
    fq.push({i,j});
    while(!fq.empty()){
        int x = fq.front().first;
        int y = fq.front().second;
        fq.pop();
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(0 > nx || nx >= h || 0 > ny || ny >= w) continue;
            if(fireVisited[nx][ny]) continue;
            if(building[nx][ny]=='#') continue;
            fireVisited[nx][ny] = 1;
            building[nx][ny] = '*';
            fq.push({nx,ny});

        }
    }
}

void fired(){
    queue <pii> fq;
    int flag = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(building[i][j] == '*' && !fireVisited[i][j] ){
                fireVisited[i][j] = 1;
                fq.push({i,j});
    
            }
        }
    }
    while(!fq.empty()){
        int x = fq.front().first;
        int y = fq.front().second;
        fq.pop();
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(0 > nx || nx >= h || 0 > ny || ny >= w) continue;
            if(fireVisited[nx][ny]) continue;
            if(building[nx][ny]=='#') continue;
            fireVisited[nx][ny] = 1;
            building[nx][ny] = '*';
            fq.push({nx,ny});

        }
    }
}

void printBuilding(){
    cout << '\n';
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << building[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int bfs(int i, int j){
    queue <pii> q;
    visited[i][j] = 1;
    q.push({i,j});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
        }
    }
    return 0;
}

int main(){
    cin >> t;
    while(t--){
       
        memset(visited,0,sizeof(visited));
        memset(fireVisited,0,sizeof(fireVisited));

        cin >> w >> h;
        for(int i = 0; i < h; i++){
            cin >> building[i];
        }
        for(int i = 0; i < 10; i++){
            fired();
            printBuilding();
        }
    }
}