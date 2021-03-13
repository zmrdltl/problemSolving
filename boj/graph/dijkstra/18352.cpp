#include <bits/stdc++.h>
#define INF 0x3f3f3f3f;
using namespace std;
using pii = pair<int,int>;
int n,m,k,x;

vector<pii> road[300001];
int dist[300001];

void dijkstra(int start){
    priority_queue <pii,vector<pii>,greater<pii>> pq;
    pq.push({0,start});
    dist[start] = 0;
    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(cost > dist[cur]) continue;
        for(int i = 0; i < road[cur].size(); i++){
            int next = road[cur][i].second;
            int nextCost = road[cur][i].first;
            if(cost + nextCost < dist[next]){
                dist[next] = cost + nextCost;
                pq.push({dist[next],next});
            }
        }
    }
}

int main(){
    cin >> n >> m >> k >> x;
    for(int i = 1; i <= n; i++) dist[i] = INF;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        road[u].push_back({1,v});
    }
    dijkstra(x);
    int flag = 0;
    for(int i = 1; i <= n;i++) {
        if(dist[i] == k) {
            cout << i << '\n';
            flag = 1;
        }
    }
    if(!flag) cout << -1 << '\n';
}