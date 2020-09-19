#include <iostream>
#include <vector>
using namespace std;

int n;
int parent[100001];
vector <int> v[100001];

void dfs(int x){
    for(int i = 0; i < v[x].size(); i++){
        if(!parent[v[x][i]]){
            parent[v[x][i]] = x;
            dfs(v[x][i]);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i< n-1; i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    dfs(1);
    for(int i = 2; i<= n; i++){
        cout << parent[i] << '\n';
    }
}