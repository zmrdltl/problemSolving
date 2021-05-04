//TODO
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f;
using namespace std;
using pii = pair<int,int>;
int n, e, d[801];
vector <pii> graph[801];

int dijkstra(){
    
}

int main(){
    cin >> n, e;
    for(int i = 0; i <= n; i++) d[i] = INF;

    while(e--){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
}