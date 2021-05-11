#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int,int>;
int n, m, x, ans, dist[1001];
vector <pii> graph[1001];

int dijkstra(int start,int end){
    priority_queue <pii,vector<pii>,greater<pii>> pq;
    pq.push({0,start});
    dist[start] = 0;
    while(!pq.empty()){
        int curCost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(curCost > dist[cur]) continue;

        for(auto el : graph[cur]){
            int next = el.first;
            int nextCost = el.second;
            if(curCost + nextCost < dist[next]){
                dist[next] = curCost + nextCost;
                pq.push({dist[next],next});
            }
        }
    }
    return dist[end];
}

int main(){
    cin >> n >> m >> x;

    for(int i = 0; i < m; i++){
        int u,v,cost;
        cin >> u >> v >> cost;
        graph[u].push_back({v,cost});
    }

    for(int i = 1; i <= n; i++){
        memset(dist,INF,sizeof(dist));
        int go = dijkstra(i,x);
        memset(dist,INF,sizeof(dist));
        int come = dijkstra(x,i);
        ans = max(ans,go + come);
    }
    cout << ans << '\n';
}