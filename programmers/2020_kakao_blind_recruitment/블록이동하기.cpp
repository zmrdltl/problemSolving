#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
int n;
vvi board;
//상,하,좌,우
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

struct Robot{
    int r1, c1, r2, c2;
    Robot(int r1, int c1, int r2, int c2): r1(r1), c1(c1), r2(r2), c2(c2){}

    Robot move(int d){
        return Robot(r1+dy[d], c1+dx[d], r2+dy[d], c2+dx[d]);
    }

    pair<Robot,Robot> rotate(int d){
        return {Robot(r1, c1, r1+dy[d], c1+dx[d]), Robot(r2, c2, r2+dy[d], c2+dx[d])};
    }
};

bool isFinished(Robot &r){
    return r.r1 == n - 1 && r.c1 == n - 1 || r.r2 == n - 1 && r.c2 == n - 1;
}

bool isValid(Robot r){
    return r.r1>=0 && r.c1>=0 && r.r2>=0 && r.c2>=0 &&
    r.r1<n && r.c1<n && r.r2<n && r.c2<n &&
    !board[r.r1][r.c1] && !board[r.r2][r.c2];
}

// Robot 구조체를 map의 원소로 사용하기 위한 오버라이딩
bool operator < (Robot a, Robot b){
    return tie(a.r1, a.c1, a.r2, a.c2) < tie(b.r1, b.c1, b.r2, b.c2);
}

// map 안에서의 Robot 중복 처리를 위한 오버라이딩
bool operator == (Robot a, Robot b){
     return tie(a.r1, a.c1, a.r2, a.c2)==tie(b.r1, b.c1, b.r2, b.c2)
    || tie(a.r1, a.c1, a.r2, a.c2)==tie(b.r2, b.c2, b.r1, b.c1);
}

map<Robot, int> dist;

// 로봇의 평행이동 반환
vector<Robot> getMoved(Robot& r){
    vector<Robot> ret;
    for(int i = 0; i < 4; i++)
        ret.push_back(r.move(i));
    return ret;
}

vector<Robot> getRotated(Robot& r){
    vector<Robot> ret;
    for(int i = 0; i < 4; i++){
        if(!isValid(r.move(i))) continue;
        pair<Robot,Robot> res = r.rotate(i);
        ret.push_back(res.first);
        ret.push_back(res.second);
    }
    return ret;
}

int bfs(){
    dist[{0,0,0,1}] = 0;

    queue<Robot> q;
    q.push({0,0,0,1});

    while(!q.empty()){
        Robot cur = q.front();
        q.pop();

        int curDist = dist[cur];
        if(isFinished(cur)) return curDist; // 목적지 도착

        vector<Robot> next[2] = {getMoved(cur), getRotated(cur)};

        for(int i = 0; i < 2; i++){
            for(Robot r: next[i]){
                if(dist.find(r) != dist.end()) continue;
                if(!isValid(r)) continue;
                dist[r] = curDist+1;
                q.push(r);
            }
        }
    }
}

int solution(vvi b){
    board = b;
    n = board.size();
    int answer = bfs();
    return answer;
}