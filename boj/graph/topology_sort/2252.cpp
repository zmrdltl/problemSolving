#include <bits/stdc++.h>
using namespace std;
int n,m;
int indegree[40000], ck[40000];
vector <int> graph[40000];
stack <int> st;

void dfs(int x){
    ck[x] = 1;
    for(auto g : graph[x]){
        if(ck[g]) continue;
        dfs(g);
    }
    st.push(x);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for(int i = 1; i <= n; i++){
        if(!ck[i]) dfs(i);
    }
    
    while(!st.empty()) cout << st.top() << ' ', st.pop();
}