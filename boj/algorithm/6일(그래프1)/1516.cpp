#include <bits/stdc++.h>
using namespace std;
int n, ind[501];


struct Edge {int v, w; };
vector <Edge> building(501);
vector <int> graph[501];

bool operator < (const Edge &a, const Edge &b){
    if(a.w != b.w) return a.w > b.w; 
    return a.v > b.v;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, cost;
        cin >> cost;
        building[i].w = cost;

        while(1){
            cin >> x;
            if(x == -1) break;
            graph[x].push_back(i);
            ind[i]++;
        }
    }
    priority_queue <Edge> pq;
    for(int i = 1; i <= n; i++){
        if(!ind[i]) pq.push({i,building[i].w});
    }

    while(!pq.empty()){
        int x = pq.top().v;
        int cost = pq.top().w;
        pq.pop();
        for(auto next : graph[x]){
            ind[next]--;
            if(!ind[next]){
                building[next].w += building[x].w;
                pq.push({next,building[next].w});
            }
        }
    }
    
    for(int i = 1; i <= n; i++) cout << building[i].w << '\n';
}