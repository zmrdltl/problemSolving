#include <iostream>
#include <vector>
using namespace std;
int t;

int find(int a, vector<int> &parent){
    if(a == parent[a]) return a;
    return find(parent[a],parent);
}

void unionParent(int x, int y, vector<int> &parent){
    int a = find(x,parent);
    int b = find(y,parent);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main(){
    cin >> t;
    while(t--){
        int n,m,ans=0;
        cin >> n >> m;
        vector <int> parent(n + 1);
        vector <int> graph[n + 1];

        for(int i = 1; i <= n; i++) parent[i] = i;

        for(int i = 0; i < m; i++){
            int u,v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(int i  = 0 ; i < n; i++){
            for(int j = 0; j < graph[i].size(); j++){
                if(find(i,parent) != find(graph[i][j],parent)){
                    unionParent(i,graph[i][j],parent);
                    ans++;
                }
            }
        }

        cout << ans <<'\n';
    }
}