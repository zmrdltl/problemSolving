#include <bits/stdc++.h>
using namespace std;
int t, n, ans;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        ans = 0;
        for(int i = 0, a, b, c; i < n; i++){
            cin >> a >> b >> c;
            int profit = max({a,b,c});
            if(profit <= 0) continue;
            ans += profit;
        }
        cout << ans << '\n';
    }
}