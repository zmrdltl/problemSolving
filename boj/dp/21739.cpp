#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll d[10001] = { 1 }, MOD = 1e9+7;
int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++){
            d[i] = (d[i] + d[j] * d[i-j-1] % MOD) % MOD;
        }
    }
    cout << d[n];
}