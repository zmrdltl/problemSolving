//TODO
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using tpiii = tuple<int,int,int>;
struct Info {int v, cost = INF, shame = 0; };
int n, m, s, e, money, ck[11];
Info dist[11];
vector <Info> graph[11];

int dijkstra(){
    ck[s] = 1;
    dist[s] = {0,0};
    priority_queue <tpiii> pq;
    //수치심 , 거리 , 현재
    pq.push({0,0,s});
    while(!pq.empty()){
        int shame = get<0>(pq.top());
        int cost = get<1>(pq.top());
        int cur = get<2>(pq.top());
        pq.pop();
        for(auto nextGraph : graph[cur]){
            int next = nextGraph.v;
            int nextCost = nextGraph.cost;
            int nextShame = nextGraph.shame;
            if(dist[next].cost > cost + nextCost){
                dist[next].cost = cost + nextCost;
                dist[next].shame = max(dist[next].shame,nextShame);
                pq.push({dist[next].shame, dist[next].cost, next});
            }
        }
    }

    for(int i = s; i <= e; i++){
        cout << dist[i].cost << ' ' ;
    }
    cout << '\n';
    return dist[e].shame;
}

int main(){
    cin >> n >> m >> s >> e >> money;
    for(int i = 0,u,v,c; i < m; i++){
        cin >> u >> v >> c;
        graph[u].push_back({v,c,c});
        graph[v].push_back({u,c,c});
    }

    cout << dijkstra();
}