#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int adj[501][501], degree[501];
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(adj[i][k] && adj[k][j]) 
                    adj[i][j] = 1;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(adj[i][j]) degree[i]++, degree[j]++;

    for(int i = 1; i <= n; i++) 
        if(degree[i] == n - 1) ans++;
        
    cout << ans << '\n';
}