#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
using pll = pair<ll,ll>;

vector <pll> graph[5001];
ll dist[5001], ck[5001];
ll n,q;

ll bfs(ll k, ll start){
    ll ans = 0;
    queue <pll> q;
    q.push({start,INF});
    dist[start] = 0;
    ck[start] = 1;
    while(!q.empty()){
        ll cur = q.front().first;
        ll curCost = q.front().second;
        q.pop();
        for(auto el : graph[cur]){
            ll next = el.first;
            ll nextCost = el.second;
            if(ck[next]) continue;
            ck[next] = 1;
            if(!dist[cur]) dist[next] = nextCost;
            else dist[next] = min(dist[cur], nextCost);
            q.push({next,nextCost});
        }
    }
    for(int i = 1; i <= n; i++)
        if(dist[i] >= k) ans++;
    return ans;
}

int main(){
    cin >> n >> q;
    for(ll i = 0; i < n - 1; i++){
        ll p, q, r;
        cin >> p >> q >> r;
        graph[p].push_back({q,r});
        graph[q].push_back({p,r});
    }
    
    for(ll i = 0; i < q; i++){
        ll k, v;
        cin >> k >> v;
        memset(dist,INF,sizeof(dist));
        memset(ck,0,sizeof(ck));
        cout << bfs(k,v) << '\n';
    }
}