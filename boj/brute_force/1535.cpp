#include <bits/stdc++.h>
using namespace std;
int n, l[21], j[21];

int dfs(int depth, int curStrength, int happy){
    if(curStrength <= 0) return 0;
    if(depth == n + 1){
        return happy;
    }
    int ans = 0;
    ans = max(ans, dfs(depth + 1, curStrength - l[depth], happy + j[depth]));
    ans = max(ans, dfs(depth + 1, curStrength, happy));
    return ans;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> l[i];
    for(int i = 1; i <= n; i++) cin >> j[i];
    cout << dfs(0,100,0);
}