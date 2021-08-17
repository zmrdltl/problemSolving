#include <bits/stdc++.h>
using namespace std;
int n, m, s, e;
vector<int> route[200001];
vector<int> whichRoute[200001];
int routeCk[200001];
int dist[200001];

int bfs(int i){
    queue <int> q;
    int routeName = whichRoute[i][0];
    routeCk[routeName] = 1;
    for(auto r : route[routeName]){
        q.push(r); //s가 속한 호선
    }

    while(!q.empty()){
        int x = q.front();
        q.pop();
        //cout << "X station : " << x << '\n';
        if(x == e) return dist[x];
        for(auto next : route[x]){
            if(routeCk[next]) continue;
            routeCk[next] = 1;
            if(next > 100000) dist[next] = dist[x] + 1;
            else dist[next] = dist[x];
            //cout << "NEXT : " << next << '\n';
            q.push(next);
        }
    }
    return -1;

}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        while(1){
            int v;
            cin >> v;
            if(v == -1) break;
            route[v].push_back(i+100000);
            route[i+100000].push_back(v);
            //v가 속한 호선
            whichRoute[v].push_back(i + 100000);
        }
    }
    cin >> s >> e;
    cout << bfs(s);
}