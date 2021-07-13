#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int,int>;
int vertex,edge, start;
int dist[20001];

struct Edge { int v, w; };
vector <Edge> graph[20001];

void dijkstra(int start){
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0,start});
    while(!pq.empty()){
        int cost = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if(dist[x] < cost) continue;
        for(auto g : graph[x]){
            if(dist[g.v] > g.w + cost){
                dist[g.v] = g.w + cost;
                pq.push({dist[g.v], g.v});
            }
        }
    }
}

int main(){
    memset(dist,INF,sizeof(dist));
    cin >> vertex >> edge >> start;
    for(int i = 0; i < edge; i++){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }
    
    dijkstra(start);
    for(int i = 1; i <= vertex; i++){
        if(dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
}