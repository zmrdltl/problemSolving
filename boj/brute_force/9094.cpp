#include <bits/stdc++.h>
using namespace std;
int n, m, t, ans;
int main(){
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n >> m;
        for(int a = 1; a < n; a++){
            for(int b = 1; b < n; b++){
                if(a >= b) continue;
                double res = (double)(a*a + b*b + m) / (a*b);
                if(res == (int)res) ans++;
            }
        }
        cout << ans << '\n';
    }
}