#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int parent[1000001], n, m;

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main(){
    fastio;
    cin >> n >> m;
    for(int i = 0; i <= n; i++) parent[i] = i;
    while(m--){
        int op, a, b;
        cin >> op >> a >> b;
        if(!op) merge(a,b);
        else {
            if(find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}