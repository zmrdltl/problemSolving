#include <bits/stdc++.h>
using namespace std;
int n,ans;
void dfs(int sum){
    if (sum > n) return;
    dfs(sum * 10 + 7);
    dfs(sum * 10 + 4);
    ans = max(ans, sum);
}

int main(){
    cin >> n;
    dfs(0);
    cout << ans;
}