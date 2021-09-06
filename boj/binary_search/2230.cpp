#include <bits/stdc++.h>
using namespace std;
int n, m, a[100001], ans = 0x3f3f3f3f;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        auto idx = lower_bound(a, a + n, a[i] + m);
        if(idx != a + n)
            ans = min(ans,abs(a[i] - *idx));
    }
    cout << ans;
}