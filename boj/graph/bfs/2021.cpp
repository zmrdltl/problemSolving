#include <bits/stdc++.h>
using namespace std;
int n, m, s, e;
vector<int> route[200001];
int dist[200001];

int bfs(){
    queue <int> q;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x == e) return dist[x] - 1 > 0 ? dist[x] - 1 : 0;
        for(auto next : route[x]) {
            if(dist[next] > -1) continue;
            if(next > 100000) dist[next] = dist[x] + 1;
            else dist[next] = dist[x];
            q.push(next);
        }
    }
    return -1;
}

int main(){
    memset(dist,-1,sizeof(dist));
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        while(1){
            int v;
            cin >> v;
            if(v == -1) break;
            route[v].push_back(i+100000);
            route[i+100000].push_back(v);
        }
    }
    
    cin >> s >> e;
    cout << bfs();
}