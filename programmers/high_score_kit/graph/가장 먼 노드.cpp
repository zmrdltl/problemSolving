#include <bits/stdc++.h>
#define MAX 0x3f3f3f3f
using namespace std;

int bfs(vector<int> graph[],vector <int> &dist, int n){
    queue <int> q;
    int visited[20001], maxDist = 0,cnt = 0;;
    memset(visited,0,sizeof(visited));
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < graph[x].size(); i++){
            int nx = graph[x][i];
            if(visited[nx]) continue;
            visited[nx] = 1;
            dist[nx] = dist[x] + 1;
            maxDist = max(maxDist, dist[nx]);
            q.push(nx);
        }
    }
    for(int i = 1; i<= n; i++){
        if(dist[i] == maxDist) cnt++;
    }
    return cnt;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector <int> dist(edge.size(),0);
    vector <int> graph[n+1];
    sort(edge.begin(),edge.end());
    for(int i = 0; i < edge.size(); i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }  
    return bfs(graph,dist,n);
}