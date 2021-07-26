#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, m, v, snail[200001];

int main(){
    fastio;
    cin >> n >> m >> v;
    for(int i = 0; i < n; i++) cin >> snail[i];
    v--;
    int cycle = n - v;
    for(int i = 1, k; i <= m; i++){
        cin >> k;
        if(k < n) cout << snail[k] << '\n';
        else cout << snail[(k-v) % cycle + v] << '\n';
    }
}