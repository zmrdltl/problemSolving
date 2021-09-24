#include <bits/stdc++.h>
using namespace std;
struct Edge{int v, w;};
vector <Edge> graph[10001];
int u, v, w, ck[10001], maxAns, edgeCnt, curCost;

void dfs(int cur, int cost){
    curCost = max(curCost, cost);
    ck[cur] = 1;
    int ret = 0;
    for(auto n : graph[cur]){
        if(ck[n.v]) continue;
        dfs(n.v, cost + n.w);
    }
}

int main(){
    while(cin >> u >> v >> w) {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        edgeCnt++;
    }

    for(int i = 1; i <= edgeCnt + 1; i++){
        memset(ck, 0, sizeof(ck));
        curCost = 0;
        dfs(i, 0);
        maxAns = max(maxAns, curCost);
    }

    cout << maxAns;
}