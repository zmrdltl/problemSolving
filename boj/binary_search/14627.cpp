#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll s, c, ans, greenOnion[1000001];

ll binarySearch(){
    ll l = 1;
    ll r = 0x3f3f3f3f;
    while(l<=r){
        ll cnt = 0;
        ll mid = (l + r) / 2;
        for(int i = 0; i < s; i++) cnt += greenOnion[i] / mid;
        if(cnt < c) r = mid - 1;
        else l = mid + 1;
    }
    return r;
}

int main(){
    cin >> s >> c;
    for(int i = 0; i < s; i++) cin >> greenOnion[i];
    ll amount = binarySearch();
    for(int i = 0; i < s; i++) ans += greenOnion[i];
    cout << ans - amount * c << '\n';
}