#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int ck[5][5];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int bfs(int i, int j, vector<string>place){
    queue <pii> q;
    q.push({i,j});
    ck[i][j] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(0 > nx || nx >= 5 || 0 > ny || ny >= 5) continue;
            if(place[nx][ny] == 'X' || ck[nx][ny]) continue;
            ck[nx][ny] = ck[x][y] + 1;
            if(place[nx][ny] == 'P'){
                if(ck[nx][ny] <= 3) return 0;
            }
            q.push({nx,ny});
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i = 0; i < places.size(); i++){
        int flag = 1;
        for(int j = 0; j < places[i].size(); j++){
            for(int k = 0; k < places[i][j].size(); k++){
                memset(ck,0,sizeof(ck));
                if(places[i][j][k]=='P' && !ck[j][k] ){
                    flag = bfs(j,k,places[i]);
                    if(!flag) break;
                }
            }
            if(!flag) break;
        }
        if(!flag) answer.push_back(0);
        else answer.push_back(1);
    }
    return answer;
}