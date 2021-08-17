#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int,int>;
struct Edge {int v, cost; };
int vertexNum, edgeNum, point, dist[5001];
vector <Edge> graph[5001];

int dijkstra(int startPoint, int endPoint){
    memset(dist,INF,sizeof(dist));
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push({0,startPoint});
    dist[startPoint] = 0;
    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur] < cost) continue;
        for(auto nextGraph : graph[cur]){
            int next = nextGraph.v;
            int nextCost = nextGraph.cost;
            if(dist[next] > cost + nextCost){
                dist[next] = cost + nextCost;
                pq.push({dist[next],next});
            }
        }
    }

    return dist[endPoint];
}

int main(){
    cin >> vertexNum >> edgeNum >> point;
    for(int i = 0,a,b,c; i < edgeNum; i++){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    if(dijkstra(1,point) + dijkstra(point,vertexNum) <= dijkstra(1,vertexNum)){
        cout << "SAVE HIM";
    }
    else cout << "GOOD BYE";
}