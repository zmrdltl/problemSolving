#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, m;
int parent[1000001];


int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b) parent[a] = b;
}

int main(){
    fastio;
    cin >> n >> m;
    for(int i = 0; i <= n; i++) parent[i] = i;
    //��ȣ �����ְ� �θ� 
    for(int i = 0; i < m; i++){
        int op, a, b;
        cin >> op >> a >> b;
         //������
        if(op == 0) {
            merge(a,b);
        }

        else {
            if(find(a) != find(b)) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}