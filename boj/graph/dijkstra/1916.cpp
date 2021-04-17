#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using vii = vector<pair<int,int>>;
using pii = pair<int,int>;
int n,m, startCity, endCity, dist[1001];
vii graph[1001];

int dijsktra(){
    dist[startCity] = 0;
    priority_queue <pii,vector<pii>,greater<pii>> pq;
    pq.push({0,startCity});
    while(!pq.empty()){
        int curCost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(curCost > dist[cur])continue;
        for(int i = 0; i < graph[cur].size(); i++){
            int nextCost = graph[cur][i].second;
            int next = graph[cur][i].first;
            if(dist[next] <= curCost + nextCost) continue;
            dist[next] = curCost + nextCost;
            pq.push({dist[next],next});
        }
    }
    return dist[endCity];
}
int main(){
    cin >> n >> m;
    for(int i = 0; i <= n; i++) dist[i] = INF;

    while(m--){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        
    }

    cin >> startCity >> endCity;
    cout << dijsktra() <<'\n';

}