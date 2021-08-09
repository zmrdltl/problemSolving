#include <bits/stdc++.h>
using namespace std;
struct Node {int v, cost; };
int n, m, dist[1001];
vector <Node> graph[1001];

int bfs(int start, int end){
    queue <int> q;
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto next : graph[x]){
            if(dist[next.v] >= 0) continue;
            dist[next.v] = dist[x] + next.cost;
            q.push(next.v);
        }
    }
    return dist[end];
}

int main(){
    cin >> n >> m;
    for(int i = 0, u,v, cost; i < n - 1; i++){
        cin >> u >> v >> cost;
        graph[u].push_back({v,cost});
        graph[v].push_back({u,cost});
    }
    

    while(m--){
        int start, end;
        cin >> start >> end;
        memset(dist,-1,sizeof(dist));
        cout << bfs(start, end) << '\n';
    }
}