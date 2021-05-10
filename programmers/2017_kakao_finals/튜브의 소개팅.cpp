#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
using pllll = tuple<ll,ll,ll,ll>;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int M, N, S;
ll speakTime[51][51];

vector<vector<int>> board;

vector <int> dijsktra(){
    vector <ll> answer = {INF,INF};
    speakTime[0][0] = 0;
    priority_queue <pllll,vector<pllll>,greater<pllll>> pq;
    //dist, s, x, y
    pq.push({0,0,0,0});
    while(!pq.empty()){
        auto [dist,cost,x,y] = pq.top();
        
        pq.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(0 > nx || nx >= M || 0 > ny || ny >= N) continue;

            ll nextCost = board[nx][ny];

            if(board[nx][ny] == -1 || cost + nextCost > S) continue;

            if(cost + nextCost < speakTime[nx][ny]){
                speakTime[nx][ny] = cost + nextCost;
                pq.push({dist+1,speakTime[nx][ny],nx,ny});
                if(nx != M - 1 || ny != N - 1) continue;
                if(answer[0] < dist + 1) continue;
                answer[0] = dist+1;
                answer[1] = speakTime[nx][ny];
            }
        }
    }

    int a = answer[0];
    int b = answer[1];

    return {a,b};
}

vector<int> solution(int m, int n, int s, vector<vector<int>> time_map) {
    M = m, N = n, S = s, board = time_map;
    for(int i = 0; i <= 50; i++)
        for(int j = 0; j <= 50; j++) speakTime[i][j] = INF;
    return dijsktra();
}
