#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main(){
    cin >> n;
    for(int i = 0, x; i < n; i++){
        cin >> x;
        ans = max(ans,x);
    }
    cout << ans;
}