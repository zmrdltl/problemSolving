//TODO
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int popular[11], ck[11],n;
vector <int> comb;
vector <int> graph[11];

int getArea(){
    int cnt = 0;
    int bfsCk[11] = {0};
    queue <int> q;
    for(int i = 1; i <= n; i++){
        if(!bfsCk[i]){
            q.push(i);
            cnt++;
            while(!q.empty()){
                int x = q.front();
                q.pop();
                for(auto next : graph[x]){
                    if(bfsCk[next]) continue;
                    bfsCk[next] = 1;
                    q.push(next);
                }
            }
        }
    }
    if(cnt > 1) return 0;
    return 1;
}
void dfs(int depth, int idx, int m){
    if(depth == m){
        vector <int> graphCopy[11];
        for(int i = 1; i <= n; i++) graphCopy[i] = graph[i];
        
        map <int,int> m,m2;
        vector <int> other;
        for(auto c : comb) m[c] = 1;

        for(int i = 1; i <= n; i++)
            if(!m[i]) m2[i] = 1;

        return;
    }

    for(int i = 1; i < n; i++){
        if(ck[i]) continue;
        ck[i] = 1;
        comb.push_back(i);
        dfs(depth+1,idx+1,m);
        comb.pop_back();
        ck[i] = 0;
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> popular[i];
    }
    for(int i = 0; i < n; i++){
        int u;
        cin >> u;
        for(int j = 0; j < u; j++){
            int v;
            cin >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    if(!getArea(graph)){
        cout << -1 << '\n';
        return 0;
    }
    for(int i = 1; i <= n/2; i++){
        memset(ck,0,sizeof(ck));
        dfs(0,0,i);
    }
}