#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, m, num[100001], sum[100001];

int main(){
    fastio;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> num[i], sum[i] = sum[i-1] + num[i];

    for(int i = 1; i <= m; i++){
        int a,b;
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << '\n';
    }
}