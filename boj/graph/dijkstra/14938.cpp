#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int,int>;
struct Edge {int v, w; };
int n, m, r, dist[101], items[101], ans;
vector <Edge> graph[101];

int dijkstra(int start){
    int totalItem = 0;
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(dist[cur] < cost ) continue;
        for(auto g : graph[cur]){
            int next = g.v;
            int nextCost = g.w;
            if(cost + nextCost < dist[next]) {
                dist[next] = cost + nextCost;
                pq.push({dist[next], next});
            }
        }
    }
    for(int i = 1; i <= n; i++)
        if(dist[i] <= m)
            totalItem += items[i];
    return totalItem;
}

int main(){
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++) cin >> items[i];
    while(r--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    for(int i = 1; i <= n; i++) {
        memset(dist, INF, sizeof(dist));
        ans = max(ans, dijkstra(i));
    }
    cout << ans;
}