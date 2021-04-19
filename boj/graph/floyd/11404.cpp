#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int dist[101][101];
int n,m;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            dist[i][j] = INF;
    }

    for(int i = 0; i < m; i++){
        int start,end,weight;
        cin >> start >> end >> weight;
        if(dist[start][end] > weight)
            dist[start][end] = weight;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][k] == INF || dist[k][j] == INF) continue;
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dist[i][j] == INF || i == j) cout << 0 << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}