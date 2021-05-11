#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
using pii = pair<int,int>;
int n, e, v1, v2, d[801];
vector <pii> graph[801];

int dijkstra(int start, int end){
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push({0,start});
    d[start] = 0;
    while(!pq.empty()){
        int curCost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(d[cur] < curCost) continue;
        for(auto &el : graph[cur]){
            int next = el.first;
            int nextCost = el.second;
            if(curCost + nextCost < d[next]){
                d[next] = curCost + nextCost;
                pq.push({d[next],next});
            }
        }
    }
    return d[end];
}

int main(){
    cin >> n >> e;

    while(e--){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    cin >> v1 >> v2;
    memset(d,INF,sizeof(d));
    ll aToV1 = dijkstra(1, v1);

    memset(d,INF,sizeof(d));
    ll v1ToV2 = dijkstra(v1,v2);
    
    memset(d,INF,sizeof(d));
    ll v2Tob = dijkstra(v2,n);

    memset(d,INF,sizeof(d));
    ll aToV2 = dijkstra(1, v2);

    memset(d,INF,sizeof(d));
    ll v2ToV1 = dijkstra(v2,v1);

    memset(d,INF,sizeof(d));
    ll v1Tob = dijkstra(v1,n);

    ll ans = aToV1 + v1ToV2 + v2Tob;
    ll ans2 = aToV2 + v2ToV1 + v1Tob;

    if(ans >= INF && ans >= INF) cout << -1;
    else cout << min(ans,ans2);
}