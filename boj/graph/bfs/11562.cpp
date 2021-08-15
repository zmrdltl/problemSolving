#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 0x3f3f3f3f
using namespace std;
int n, m, k, adj[251][251];

int main(){
    fastio;
    memset(adj,INF,sizeof(adj));
    cin >> n >> m;

    for(int i = 0,u,v,b; i < m; i++){
        cin >> u >> v >> b;
        adj[u][v] = 0;
        if(!b) adj[v][u] = 1;
        if(b) adj[v][u] = 0;
    }

    for(int t = 1; t <= n; t++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) adj[i][j] = 0;
                adj[i][j] = min(adj[i][j], adj[i][t] + adj[t][j]);
            }
        }
    }

    cin >> k;

    for(int i = 0,u,v; i < k; i++){
        cin >> u >> v;
        cout << adj[u][v] << '\n';
    }
}