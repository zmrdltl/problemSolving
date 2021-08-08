#include <bits/stdc++.h>
using namespace std;
int n, ck[10001];
int peoplePerVilage[10001];
vector <int> graph[10001];
int d[10001][2]; //0은 일반 , 1은 우수마을

void dfs(int x){
    if(ck[x]) return;
    ck[x] = 1;
    d[x][0] = 0;
    d[x][1] = peoplePerVilage[x];
    for(auto next : graph[x]){
        if(ck[next]) continue;
        dfs(next);
        d[x][1] += d[next][0];
        d[x][0] += max(d[next][0], d[next][1]);
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> peoplePerVilage[i];
    }

    for(int i = 1,u,v; i <= n - 1; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    dfs(1);
    cout << max(d[1][0], d[1][1]);
}