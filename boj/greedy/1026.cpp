#include <bits/stdc++.h>
using namespace std;
int a[51],b[51],n,ans;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a,a+n);
    sort(b,b+n);
    for(int i = 0; i < n; i++){
        ans += a[i] * b[n-i-1];
    }
    cout << ans << '\n';
}