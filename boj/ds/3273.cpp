#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, ans, x;
map<ll,ll> m;
int main(){
    cin >> n;
    while(n--){
        ll x;
        cin >> x;
        m[x] = 1;
    }
    cin >> x;
    for(auto &el : m) 
        if(m[x - el.first] && m[el.first]) ans++;
    cout << ans/2 << '\n';
}