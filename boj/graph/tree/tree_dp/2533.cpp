#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> graph[1000001];
vector <int> graph2[1000001];
int d[1000001][2];
int visited[1000001];
//본인이 얼리어답터라면 자식은 얼리어답터여도 된다.
//본인이 얼리어답터가 아니라면 자식은 무조건 얼리어답터여야 한다.

void dfs(int node){
    visited[node] = true;
    for(int i = 0; i < graph[node].size(); i++){
        int next = graph[node][i];
        if(visited[next]) continue;
        graph2[node].push_back(next);
        dfs(next);
    }
}

int getAdaptor(int node, bool early){
    int &ans = d[node][early];
    if(ans != -1) return ans;
    if(early){
        ans = 1;
        for(int i = 0; i < graph2[node].size(); i++){
            int next = graph2[node][i];
            ans += min(getAdaptor(next,true), getAdaptor(next,false));
        }
    }
    
    else{
        ans = 0; //얼리가 아님
        for(int i = 0; i < graph2[node].size(); i++){
            int next = graph2[node][i];
            ans += getAdaptor(next,true);
        }
    }
    return ans;
}



int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(d,-1,sizeof(d));
    dfs(1);
    cout << min(getAdaptor(1,false),getAdaptor(1,true));
}