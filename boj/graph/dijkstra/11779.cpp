#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int,int>;
int n, m, startCity, endCity, dist[1001], previous[1001];
struct Edge{ int v, w; };
vector <Edge> graph[1001];
stack <int> route;

void dfs(int x){
    route.push(x);
    if(x == startCity) return;
    dfs(previous[x]);
}

void dijkstra(){
    priority_queue <pii, vector<pii>, greater<pii> > pq;
    pq.push({0,startCity});
    dist[startCity] = 0;
    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(dist[cur] < cost) continue;
        for(auto next : graph[cur]){
            if(dist[next.v] > cost + next.w){
                dist[next.v] = cost + next.w;
                previous[next.v] = cur;
                pq.push({dist[next.v],next.v});
            }
        }
    }
}

int main(){
    memset(dist,INF,sizeof(dist));
    cin >> n >> m;
    for(int i = 0, u, v, w; i < m; i++){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    cin >> startCity >> endCity;
    dijkstra();
    cout << dist[endCity] << '\n';
    dfs(endCity);
    cout << route.size() << '\n';

    while(route.size()){
        cout << route.top() << ' ';
        route.pop();
    }
}