#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int,int>;

int n,m,ans = INF;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int lab[51][51], labCopy[51][51], ck[11];
int dist[51][51], bfsCk[51][51];
vector <pii> virusPos, spreadPos;

void copyLab(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            labCopy[i][j] = lab[i][j];
}

bool isAllInfected(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(!labCopy[i][j]) return false;
    return true;
}

int bfs(int option = 0){
    int maxTime = 0; 
    memset(dist,INF,sizeof(dist));
    memset(bfsCk,0,sizeof(bfsCk));

    //option 0 : 비활성 바이러스를 벽으로 세우지 않았을 때
    if(option) for(auto &v : virusPos) labCopy[v.first][v.second] = 1; 
    for(auto &s : spreadPos) labCopy[s.first][s.second] = 3;
    
    queue <pii> q;

    for(auto &s : spreadPos){
        dist[s.first][s.second] = 0;
        q.push({s.first,s.second});
        bfsCk[s.first][s.second] = 1;
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(0 > nx || nx >= n || 0 > ny || ny >= n) continue;
            if(labCopy[nx][ny] == 1 || bfsCk[nx][ny]) continue;
            labCopy[nx][ny] = 3;
            bfsCk[nx][ny] = 1;
            dist[nx][ny] = min(dist[nx][ny],dist[x][y] + 1);
            maxTime = max(maxTime,dist[nx][ny]);
            q.push({nx,ny});
        }
    }
    
    return maxTime;
}

void activeVirus(int depth, int idx){
    if(depth == m){
        int minTime1 = INF, minTime2 = INF;
        copyLab();
        minTime1 = min(minTime1,bfs());
        if(isAllInfected()) ans = min(ans,minTime1);
        copyLab();
        minTime2 = min(minTime2,bfs(1));
        if(isAllInfected()) ans = min(ans,minTime2);
        return;
    }

    for(int i = idx; i < virusPos.size(); i++){
        if(ck[i]) continue;
        ck[i] = 1;
        spreadPos.push_back({virusPos[i].first, virusPos[i].second});
        activeVirus(depth+1,i+1);
        ck[i] = 0;
        spreadPos.pop_back();
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> lab[i][j];
            if(lab[i][j] == 2) virusPos.push_back({i,j});
        }
    }

    activeVirus(0,0);
    if(ans == INF) cout << -1;
    else cout << ans;
}