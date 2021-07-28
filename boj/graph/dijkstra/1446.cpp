#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int,int>;
int n, d, dist[10001], ans;
struct Edge { int v, w; };
vector <Edge> graph[10001];

int main(){
    memset(dist,INF,sizeof(dist));
    cin >> n >> d;
    dist[d] = d;
    
    for(int i = 0; i < n; i++){
        int u,v,w;
        cin >> u >> v >> w;
        if(v - u <= w) continue; //지름길이 아닌경우
        if(v > d) continue; //도착지점이 d 넘어가는 경우
        graph[u].push_back({v,w});
    }

    int prev = -1;    
    for(int i = 0; i <= d; i++){

        if(i) prev = dist[i-1];
        dist[i] = min(dist[i], prev + 1);

        for(auto next : graph[i]){
            if(dist[next.v] > dist[i] + next.w) 
                dist[next.v] = dist[i] + next.w;
        }
    }

    cout << dist[d];
}