#include <bits/stdc++.h>
using namespace std;
int n, stair[301],d[301][3];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> stair[i];

    d[1][1] = stair[1];

    for(int i = 2; i <= n; i++){
        d[i][1] = max(d[i-2][1],d[i-2][2]) + stair[i];
        d[i][2] = d[i-1][1] + stair[i];
    }
    cout << max(d[n][1], d[n][2]);
}   