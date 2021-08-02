#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, a[1000001], b, c, ans;
int main(){
    cin >> n;
    for(int i = 0 ; i < n; i++) cin >> a[i];
    cin >> b >> c;
    for(int i = 0; i < n; i++){
        ans += 1;
        a[i] -= b;
        if(a[i] < 0) continue;
        if(a[i] % c) ans += a[i] / c + 1;
        else ans += a[i] / c;
    }
    cout << ans << '\n';
}