#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
int N;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
vvi board;

struct Robot { int y1, x1, y2, x2; };

Robot move(int d, int x1, int y1, int x2, int y2){
    return { y1 + dy[d], x1+dx[d], y2+dy[d], x2+dx[d] };
}

pair <Robot, Robot> rotate(int d, int x1, int y1, int x2, int y2){
    return {{y1, x1, y1+dy[d], x1+dx[d]}, {y2, x2, y2+dy[d], x2+dx[d]}};
}

bool isDone(int x1, int y1, int x2, int y2){
    if((x1 == N - 1 && y1 == N-1) || (x2 == N - 1 && y2 == N - 1)) return true;
    return false;
}

bool isValid(int x1, int y1, int x2, int y2){
    if(0 > x1 || x1 >= N || 0 > y1 || y1 >= N) return false;
    if(board[y1][x1] || board[y2][x2]) return false;
    return true;
}

bool operator < (Robot a, Robot b){
    return tie(a.y1, a.x1, a.y2, a.x2) < tie(b.y1, b.x1, b.y2, b.x2);
}

bool operator == (Robot a, Robot b){
    if(tie(a.y1, a.x1, a.y2, a.x2) == tie(b.y1, b.x1, b.y2, b.x2)
    || tie(a.y1, a.x1, a.y2, a.x2)==tie(b.y2, b.x2, b.y1, b.x1)) return true;
    return false;
}

map <Robot, int> dist;

vector<Robot> getMoved(Robot& r){
    vector<Robot> ret;
    for(int i = 0; i < 4;i++) ret.push_back(move(i,r.x1,r.y1,r.x2,r.y2));
    return ret;
}

vector<Robot> getRotated(Robot& r){
    vector<Robot> ret;
    //i방향으로 움직일 수 있다면 i방향으로 회전가능
    for(int i = 0; i < 4; i++){
        Robot mr = move(i,r.x1,r.y1,r.x2,r.y2);
        if(isValid(mr.x1,mr.y1,mr.x2,mr.y2)){
            pair < Robot,Robot > res = rotate(i,r.x1,r.y1,r.x2,r.y2);
            ret.push_back(res.first);
            ret.push_back(res.second);
        }
    }
    return ret;
}

int bfs(){
    dist[{0,0,0,1}] = 0;

    queue <Robot> q;
    q.push({0,0,0,1});

    while(!q.empty()){
        int x1 = q.front().x1;
        int y1 = q.front().y1;
        int x2 = q.front().x2;
        int y2 = q.front().y2;

        q.pop();

        int curDist = dist[q.front()];
        if(isDone(x1,y1,x2,y2)) return curDist; //도착

        vector<Robot> next[2] = { getMoved(q.front()), getRotated(q.front())};

        for(int i = 0; i < 2; i++){
            for(Robot r: next[i]){
                // 이 상태가 방문한 적이 없고 유효한 상태일 경우
                if(dist.find(r) == dist.end() && isValid(r.x1,r.y1,r.x2,r.y2)){
                    dist[r] = curDist+1;
                    q.push(r);
                }
            }
        }
    }
}

int solution(vvi b){
    board = b;
    N = board.size();
    int answer = bfs();
    return answer;
}