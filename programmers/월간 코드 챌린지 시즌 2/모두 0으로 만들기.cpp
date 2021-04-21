#include <bits/stdc++.h>
#define ll long long
using namespace std;
int ck[300001];
ll cost[300001],ans;
void dfs(int cur, vector<int>graph[]){
    ck[cur] = 1;
    for(int next : graph[cur]){
        if(ck[next]) continue;
        dfs(next,graph);
        ans += abs(cost[next]);
        cost[cur] += cost[next];
    }
}

ll solution(vector<int> a, vector<vector<int>> edges) {
    ll sum = 0;
    ans = 0;
    vector<int> graph[a.size()];
    memset(ck,0,sizeof(ck));
    memset(cost,0,sizeof(cost));
    for(int i = 0; i < a.size(); i++) {
        cost[i] = a[i], sum += cost[i];
    }
    if(sum) return -1;
    for(int i = 0; i < edges.size(); i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    dfs(0, graph);
    return ans;
}