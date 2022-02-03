#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll N, w, d, sum;
int main(){
    while(cin >> N >> w >> d >> sum){
        ll fullWeight = N * (N - 1) / 2 * w;
        ll ans = (sum - fullWeight) / d;
        if(!ans) cout << N << '\n';
        else cout << ans << '\n';
    }
}