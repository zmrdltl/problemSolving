//TODO
#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
using pii = pair<int,int>;
using tpll = tuple<ll,ll,ll>;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int m, n, s;
int ck[51][51];
vector<vector<int>> board;
vector <int> graph[51];
ll dist[51][51];

void bfs(){
    queue <pii> q;
    q.push({0,0});
    ck[0][0] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= m || 0 > ny || ny >= n) continue;
            if(board[nx][ny] == -1 || ck[nx][ny]) continue;
            ck[nx][ny] = 1;
            graph[nx].push_back(ny);
            q.push({nx,ny});
        }
    }
    for(int i = 0; i < 5; i++){
        if(graph[i].size()){
            for(auto a : graph[i])
                cout << a << ' ';
            cout << '\n';
        }
    }
    cout << '\n';
}
void dijsktra(){
    dist[0][0] = 0;
    priority_queue <tpll,vector<tpll>,greater<tpll>> pq;
    pq.push({0,0,0});
    while(!pq.empty()){
        int cost = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nextCost = board[nx][ny];
            if(0 > nx || nx >= m || 0 > ny || ny >= n) continue;
            cout << "x,y -> nx,ny : " << x << ' '<< y << ' ' << nx << ' ' << ny << '\n';
            if(board[nx][ny] == -1) continue;

            if(cost + nextCost < dist[nx][ny]){
                dist[nx][ny] = cost + nextCost;
                pq.push({dist[nx][ny],nx,ny});
            }
        }
    }
}

vector<int> solution(int m, int n, int s, vector<vector<int>> time_map) {
    m = m;
    n = n; 
    s = s;
    board = time_map;
    memset(dist,INF,sizeof(dist));
    memset(ck,0,sizeof(ck));
    for(int i = 0; i <= 50; i++) graph[i].clear();
    int move_distance = 0;
    int sum_of_talk_time = 0;
    
    vector<int> answer(2);
    bfs();
    dijsktra();
    cout << dist[m-1][n-1] << '\n';
    answer[0] = move_distance;
    answer[1] = sum_of_talk_time;
    
    return answer;
}