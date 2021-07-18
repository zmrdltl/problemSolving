#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int,int>;
using tpiii = tuple<int,int,int>;

struct Edge{ int v, w; };
vector <Edge> graph[2000], reversedGraph[2000];
int dist[2000][5000], trapStatus[1001];

// void pushMinHeap(priority_queue <tpiii,vector<tpiii>,greater<tpiii>> &minHeap, int current, vector <Edge> graph[1001], int state, int cost, int op){
//     for(auto g : graph[current]){
//         int nextCost = g.w;
//         int next = g.v;
//         int nextState = state;
//         int isCurTrap = trapStatus[current] && (state & 1 << trapStatus[current]) - 1;
//         int isNextTrap = trapStatus[next] && (state & 1 << trapStatus[next]) - 1;
//         if(!op && (isCurTrap ^ isNextTrap)) continue;
//         if(op && (!isCurTrap ^ isNextTrap)) continue;
//         if(trapStatus[nextState] == 1) nextState ^= (1 << trapStatus[nextState]) - 1;
//         if(dist[next][nextState] > cost + nextCost){
//             dist[next][nextState] = cost + nextCost;
//             minHeap.push({dist[next][nextState], next, nextState});
//         }
//     }
// }

int dijkstra(int start, int end){
    dist[start][0] = 0;
    priority_queue <tpiii,vector<tpiii>,greater<tpiii>> minHeap;
    minHeap.push({0,start,0}); //cost, 정점, trap state
    while(!minHeap.empty()){
        int cost = get<0>(minHeap.top());
        int current = get<1>(minHeap.top());
        int state = get<2>(minHeap.top());
        minHeap.pop();
        if(current == end) return cost;
        if(dist[current][state] != cost) continue;
        for(auto g : graph[current]){
            int nextCost = g.w;
            int next = g.v;
            int isCurTrap = trapStatus[current] && state & 1 << trapStatus[current] - 1;
            int isNextTrap = trapStatus[next] && state & 1 << trapStatus[next] - 1;
            if(isCurTrap ^ isNextTrap) continue;
            int nextState = state;
            if(trapStatus[next]) nextState ^= 1 << trapStatus[next] - 1;
            if(dist[next][nextState] > cost + nextCost){
                dist[next][nextState] = cost + nextCost;
                minHeap.push({dist[next][nextState], next, nextState});
            }
        }
        for(auto g : reversedGraph[current]){
            int nextCost = g.w;
            int next = g.v;
            int isCurTrap = trapStatus[current] && state & 1 << trapStatus[current] - 1;
            int isNextTrap = trapStatus[next] && state & 1 << trapStatus[next] - 1;
            if(!isCurTrap ^ isNextTrap) continue;
            int nextState = state;

            if(trapStatus[next] ) nextState ^= 1 << trapStatus[next] - 1;
            if(dist[next][nextState] > cost + nextCost){
                dist[next][nextState] = cost + nextCost;
                minHeap.push({dist[next][nextState], next, nextState});
            }
        }
        
    }
    int ans = INF;
    for(auto &d : dist[end]) ans = min(ans,d);
    return ans;
}

//trap의 개수 10개 -> 상태는 눌렀나 안눌렀나뿐 -> 2^10
int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
    for(int i = 1; i <= 1000; i++) graph[i].clear(), reversedGraph[i].clear();
    memset(dist,INF,sizeof(dist));
    memset(trapStatus,0,sizeof(trapStatus));
    int cnt =0;
    for(auto t : traps){
        trapStatus[t] = ++cnt;
    }
    for(auto r : roads) {
        graph[r[0]].push_back({r[1],r[2]});
        reversedGraph[r[1]].push_back({r[0],r[2]});
    }
    return dijkstra(start,end);
}