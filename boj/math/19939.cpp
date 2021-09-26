#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k;
int main(){
    cin >> n >> k;
    ll diff = 2 * n - k * (k + 1);
    if(2 * n < k * (k + 1) ) cout << -1;
    else if(diff % k == 0) cout << k - 1;
    else cout << k;
}