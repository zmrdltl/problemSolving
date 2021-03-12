#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n, m;
vector <int> graph[501];
int visited[501];
int bfs(int start){
    int ans = 0;
    queue <int> q;
    visited[start] = 1;
    q.push(start);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < graph[x].size(); i++){
            if(visited[graph[x][i]]) continue;
            visited[graph[x][i]] = visited[x] + 1;
            if(visited[x]<=2) ans++;
            q.push(graph[x][i]);
        }
    }
    return ans;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << bfs(1);
}