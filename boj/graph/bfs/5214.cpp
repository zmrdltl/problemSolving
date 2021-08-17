#include <bits/stdc++.h>
using namespace std;
int n,m,k,dist[200001];
vector <int> graph[200001];
int bfs(){
    queue <int> q;
    q.push(1);
    dist[1] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x == n) return dist[x];
        for(auto next : graph[x]){
            if(dist[next]) continue;
            if(next > 100000) dist[next] = dist[x] + 1;
            else dist[next] = dist[x];
            q.push(next);
        }
    }
    return -1;
}

int main(){
    cin >> n >> k >> m;
    for(int i = 1; i <= m; i++){
        for(int j = 0,v; j < k; j++){
            cin >> v;
            graph[v].push_back(i + 100000);
            graph[i + 100000].push_back(v);
        }
    }
    cout << bfs();
}