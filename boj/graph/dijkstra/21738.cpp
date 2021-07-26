#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int,int>;
vector <int> block[328001];
int dist[328001];
int n, s, p;

int dijkstra(){
    priority_queue <pii,vector<pii>,greater<pii>> minHeap;
    dist[p] = 0;
    minHeap.push({0,p});
    while(!minHeap.empty()){
        int cost = minHeap.top().first;
        int cur = minHeap.top().second;
        minHeap.pop();
        if(dist[cur] < cost) continue;
        for(auto next : block[cur]){
            if(dist[next] > dist[cur] + 1 ){
                dist[next] = dist[cur] + 1;
                minHeap.push({dist[next],next});
            }
        }
    }
    sort(dist,dist + s + 1);
    return n - dist[0] - dist[1] - 1;
}

int main(){
    cin >> n >> s >> p;
    memset(dist,INF,sizeof(dist));
    for(int i = 0,a,b; i < n - 1; i++){
        cin >> a >> b;
        block[a].push_back(b);
        block[b].push_back(a);
    }
    cout << dijkstra();

}