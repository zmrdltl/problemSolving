#include <bits/stdc++.h>
using namespace std;

int n, cur, curDir;
struct Conn{ int dest, type; };
vector <Conn> graph[1001];

int main(){
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v, t;
        cin >> u >> v >> t;
        if(u == 1) cur = u, curDir = t;
        graph[u].push_back({v,t});
    }

    while(1) {
        cur = graph[cur][0].dest;
        if(cur == n) break;
        if(graph[cur][0].type) curDir = 1 - curDir;
    }
    
    cout << curDir;
}