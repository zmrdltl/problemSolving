#include <bits/stdc++.h>
using namespace std;
int n, m, parent[1001], ans, edgeCnt,treeNum, vectexNum;
map <int, char> collegeMap;
struct Edge {int u, v, w; };
vector <Edge> edges;
vector <int> graph[1001];
int ck[1001];

bool cmp(Edge &a, Edge &b){
    return a.w < b.w;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
};

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

void bfs(int i){
    ck[i] = 1;
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto next : graph[x]){
            if(ck[next]) continue;
            ck[next] = 1;
            q.push(next);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) parent[i] = i;
    for(int i = 1; i <= n; i++){
        char c;
        cin >> c;
        collegeMap[i] = c;
    }

    for(int i = 1,u,v,w; i <= m; i++){
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }

    sort(edges.begin(), edges.end(), cmp);

    for(auto e : edges){
        if(collegeMap[e.u] == collegeMap[e.v]) continue;
        if(edgeCnt == n - 1) break;
        if(find(e.u) != find(e.v)){
            merge(e.u,e.v);
            ans += e.w;
            graph[e.u].push_back(e.v);
            graph[e.v].push_back(e.u);
            edgeCnt++;
        }
    }

    for(int i = 1; i <= n; i++){
        if(ck[i]) continue;
        treeNum++;
        bfs(i);
    }

    for(int i = 1; i <= n; i++)
        if(ck[i]) vectexNum++;

    if(vectexNum == n && treeNum == 1) cout << ans;
    else cout << -1;
}