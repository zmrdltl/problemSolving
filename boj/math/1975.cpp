#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int t, n;

int f(int n, int i) {
    int cnt = 0;
    while(n) {
        if(n % i == 0) cnt++;
        else break;
        n /= i;
    }
    return cnt;
}

int main(){
    fastio;
    cin >> t;
    while(t--){
        cin >> n;
        int ans = 0;
        for(int i = 2; i <= 1000; i++) ans += f(n, i);
        cout << ans << '\n';
    }
}