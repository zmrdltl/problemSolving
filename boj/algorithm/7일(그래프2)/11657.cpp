#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
using pll = pair<ll,ll>;
ll n, m, w;
vector <pll> graph[505];

int bellmanFord(ll start,ll end,vector<ll> &dist){
    dist[start] = 0;
    for(ll i = 1; i <= end; i++){
        for(ll cur = 1; cur <= end; cur++){
            if(dist[cur] == INF) continue;
            for(auto &el : graph[cur]){
                ll next = el.first;
                ll nextCost = el.second;
                if(dist[next] > dist[cur] + nextCost){
                    dist[next] = dist[cur] + nextCost;
                    if(i == end) return -1; //음수 사이클 발생
                }
            }
        }
    }
    return 1;
}
int main(){
    cin >> n >> m;
    vector<ll> dist(n + 1,INF);

    for(ll i = 0,s,e,t; i < m; i++){
        cin >> s >> e >> t;
        graph[s].push_back({e,t});
    }
    if(bellmanFord(1,n,dist) != -1){
        for(ll i = 2; i <= n; i++) {
            if(dist[i] == INF) cout << -1;
            else cout << dist[i];
            cout << '\n';
        }
    }
    else cout << -1;
}