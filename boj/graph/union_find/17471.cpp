#include <bits/stdc++.h>
using namespace std;
int n, popular[11], comb[11], parent[11];
vector <int> graph[11];
int ans = 0x3f3f3f3f;

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int bfs(vector <int> ward){
    int ck[11] ={0};
    queue <int> q;
    q.push(ward[0]);
    ck[ward[0]] = 1;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto next : graph[x]){
            if(ck[next] || parent[next] != parent[x]) continue;
            ck[next] = 1;
            q.push(next);
        }
    }
    for(auto w : ward) if(!ck[w]) return 0;
    return 1;
}

void dfs(int depth, int idx, int range){
    if(depth == range){
        for(int j = 1; j <= n; j++) parent[j] = j;
        vector <int> ward1, ward2;
        int sum1 = 0, sum2 = 0;

        for(int i = 1; i<= n; i++){
            if(comb[i]) ward1.push_back(i), sum1 += popular[i];
            else ward2.push_back(i), sum2 += popular[i];
        }

        for(int i = 0; i < ward1.size() - 1; i++) merge(ward1[i],ward1[i+1]);
        for(int i = 0; i < ward2.size() - 1; i++) merge(ward2[i],ward2[i+1]);
        
        if(bfs(ward1) && bfs(ward2)) ans = min(ans, abs(sum1 - sum2));
        return;
    }
    for(int i = idx; i <= n; i++){
        if(comb[i]) continue;
        comb[i] = 1;
        dfs(depth + 1, i + 1, range);
        comb[i] = 0;
    }
}


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> popular[i];
    for(int i = 1, edges; i <= n; i++){
        cin >> edges;
        for(int j = 1,v; j <= edges; j++){
            cin >> v;
            graph[i].push_back(v);
            graph[v].push_back(i);
        }
    }

    for(int i = 1; i <= n/2; i++){
        memset(comb,0,sizeof(comb));
        dfs(0,1,i);
    }

    if(ans == 0x3f3f3f3f) cout << -1;
    else cout << ans;
}