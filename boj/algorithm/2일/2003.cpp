#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int a[10001], sum[10001];


int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 0; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(sum[j] - sum[i] == m) ans++;
        }
    }
    cout << ans << '\n';
}