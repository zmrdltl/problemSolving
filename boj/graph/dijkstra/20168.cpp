//TODO
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;
using pii = pair<int,int>;
int n, m, a, b, c;
struct Edge {int v, cost; };
vector<Edge> graph[11];

bool dijkstra(int k){
    vector <int> dist(n+1, INF);
    vector <bool> visit(n+1, 0);
    visit[a] = 1;
    dist[a] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,a});
    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(cur == b) return dist[b] <= c;
        for(auto nextGraph : graph[cur]){
            int next = nextGraph.v;
            int nextCost = nextGraph.cost;
            if(visit[next] || nextCost > k) continue;
            if(dist[next] > cost + nextCost){
                dist[next] = cost + nextCost;
                pq.push({dist[next],next});
            }
        }
    }
    return false;

}
int main(){
    cin >> n >> m >> a >> b >> c;
    for(int i = 0,u,v,c; i < m; i++){
        cin >> u >> v >> c;
        graph[u].push_back({v,c});
        graph[v].push_back({u,c});
    }
    int l = -1, r = 21;
    while(l + 1 < r){
        int mid = ( l + r ) / 2;
        if(dijkstra(mid)) r = mid;
        else l = mid;
    }
    if(r == 21) cout << -1;
    else cout << r;
}