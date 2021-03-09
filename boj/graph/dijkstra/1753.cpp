#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int,int>;
int V, E, start;
int dis[20001];

vector <pii> graph[20001];

void dijkstra(){
    dis[start] = 0;
    
    priority_queue<pii> pq;
    pq.push({0, start});
    while (!pq.empty()){
        pair<int, int> cur = pq.top();
        int currentDistance = -cur.first;
        int current = cur.second;
        pq.pop();

        if (currentDistance > dis[current]) continue;

        for (int i = 0; i < graph[current].size(); i++){
            int nextDistance = graph[current][i].first;
            int next = graph[current][i].second;
            if (nextDistance + currentDistance < dis[next]){
                dis[next] = nextDistance + currentDistance;
                pq.push(make_pair(-dis[next], next));
            }
        }
    }
}

int main(){
    cin >> V >> E >> start;
    for(int i = 1; i <= V; i++) dis[i] = INF;
    for(int i = 0; i < E; i++){
        int u, v, distance;
        cin >> u >> v >> distance;
        graph[u].push_back({distance,v});
    }
    dijkstra();
    for(int i = 1; i <= V; i++){
        if(dis[i] == INF) cout << "INF\n";
        else cout << dis[i] << '\n';
    }
}
