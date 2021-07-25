#include <bits/stdc++.h>
using namespace std;
int n, m, a[101];

int dfs(int idx, int cnt, int size){
    if(cnt > m) return 0;
    if(cnt == m) return size;
    int ans = 0;
    ans = max(dfs(idx + 1, cnt + 1, size + a[idx+1]), dfs(idx + 2, cnt + 1, size/2 + a[idx+2]));
    return ans;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cout << dfs(0,0,1);
}