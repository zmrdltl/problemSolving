#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int parent[1001];

struct Edge { int u, v, w; };

vector <Edge> graph;

bool cmp(Edge a, Edge b){
    return a.w < b.w;
}

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    if(find(a) != find(b)){
        parent[a] = b;
    }
}

int main(){
    cin >> n >> m;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({u,v,w});
    }
    sort(graph.begin(),graph.end(),cmp);
    for(int i = 1; i <= n; i++) parent[i] = i;
    for(int i = 0; i < graph.size(); i++){
        int aParent = find(graph[i].u);
        int bParent = find(graph[i].v);
        if(aParent != bParent){
            merge(aParent,bParent);
            ans += graph[i].w;
        }
    }
    cout << ans << '\n';
}