#include <iostream>
#include <queue>
#include <vector>
#define ll long long
#define MAX 0x3f3f3f3f
using namespace std;

struct P{
    int node,cost;
    bool operator <(const P &p) const{return cost > p.cost;}
};

vector<P> edge[50];
int djik(int v,int k){
    priority_queue <P> pq;
    vector <int> dist(v,MAX);
    dist[0] = 0;
    pq.push({0,0});
    while(!pq.empty()){
        int from = pq.top().node;
        int cost = pq.top().cost;
        pq.pop();
        if(dist[from] < cost) continue;
        for(auto &p : edge[from]){
            int to = p.node;
            int cost = p.cost;
            int ncost = dist[from] + cost;
            if(ncost < dist[to]){
                dist[to] = ncost;
                pq.push({to,dist[to]});
            }
        }
    }
    int answer =0;
    for(auto & p : dist) if(p<=k) answer ++;
    return answer;
}

int floyd(int N, vector<vector<int> > road, int K){
    int d[50][50];
    for(int i = 0; i<N; i++){
        for(int j = 0 ; j<N; j++){
            if(i==j) d[i][j] = 0; else d[i][j] = MAX;
        }
    }

    for(auto &p : road){
        int from = p[0] - 1;
        int to = p[1] - 1;
        int cost = p[2];
        d[from][to] = d[to][from] = min(cost,d[from][to]);
    }

    for(int k = 0; k<N; k++){
        for(int i = 0; i<N; i++){
            for(int j = 0 ; j<N; j++){
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    int answer = 0;
    for(int i = 0; i<N; i++){
        if(d[i][0]<=K)
            answer ++;
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j <N; j++){
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
    return answer;
}

int solution(int N, vector<vector<int> > road, int K) {
    // for(auto &p : road){
    //     edge[p[0]-1].push_back({p[1]-1,p[2]});
    //     edge[p[1]-1].push_back({p[0]-1,p[2]});
    // }
    //return djik(N, vector<vector<int> > road, int K);
    return floyd(N,road,K);
}