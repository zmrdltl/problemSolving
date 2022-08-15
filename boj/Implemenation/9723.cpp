#include <bits/stdc++.h>
using namespace std;
int t, a[3];
string ans;
int main(){
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> a[0] >> a[1] >> a[2];
        ans = "YES";
        sort(a, a + 3);
        if (a[2] * a[2] != a[0] * a[0] + a[1] * a[1]) ans = "NO";
        cout << "Case #" << i << ": " << ans << '\n';
    }
}