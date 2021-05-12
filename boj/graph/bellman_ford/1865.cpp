#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int,int>;
int tc;
int n, m, w;

vector <pii> graph[501];

bool bellmanFord(int start,int end){
    vector<int> dist(end+1,INF);
    dist[start] = 0;
    int flag = 0;
    for(int i = 1; i <= end; i++){
        flag = 0;
        for(int cur = 1; cur <= end; cur++){
            for(auto &el : graph[cur]){
                int next = el.first;
                int nextCost =el.second;
                if(dist[next] > dist[cur] + nextCost){
                    dist[next] = dist[cur] + nextCost;
                    flag = true;
                }
            }
        }
        if(!flag) return false;
    }
    return true;
}

int main(){
    cin >> tc;
    while(tc--){
        cin >> n >> m >> w;
        for(int i = 0; i <= 500; i++) graph[i].clear();
        for(int i = 0,s,e,t; i < m; i++){
            cin >> s >> e >> t;
            graph[s].push_back({e,t});
            graph[e].push_back({s,t});
        }
        for(int i = 0,s,e,t; i < w; i++){
            cin >> s >> e >> t;
            graph[s].push_back({e,-t});
        }
        if(bellmanFord(1,n)) cout << "YES\n";
        else cout << "NO\n";
    }
}