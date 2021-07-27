#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int t, n, k, vic;
int buildTime[1001], ind[1001], update[1001];


int main(){
    cin >> t;
    while(t--){
        memset(buildTime,0,sizeof(0));
        memset(ind,0,sizeof(ind));
        memset(update,0,sizeof(update));

        cin >> n >> k;

        vector <vector<int>> graph(n + 1);

        for(int i = 1; i <= n; i++) cin >> buildTime[i];
        for(int i = 0,u,v; i < k; i++){
            cin >> u >> v;
            graph[u].push_back(v);
            ind[v]++;
        }

        cin >> vic;

        priority_queue <pii,vector<pii>,greater<pii>> pq;

        for(int i = 1; i <= n; i++){
            if(!ind[i]) pq.push({buildTime[i],i});
        }

        int ans = 0x3f3f3f3f;
        while(!pq.empty()){
            int cost = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            if(cur == vic) {ans = buildTime[cur]; break;}
            for(auto next : graph[cur]){
                ind[next]--;
                if(!ind[next]){
                    buildTime[next] += buildTime[cur];
                    pq.push({buildTime[next], next});
                }
            }
        }
        
        cout << ans << '\n';
    }
}