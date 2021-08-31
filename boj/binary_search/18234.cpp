//당근 훔쳐 먹기
#include <bits/stdc++.h>
#define ll long long
using namespace std;
using pll = pair<ll,ll>;
ll n, t, ans;
vector <pll> carrot;

int main(){
    cin >> n >> t;
    carrot.resize(n);
    for(int i = 0,w,p; i < n; i++){
        cin >> w >> p;
        carrot[i] = {p,w};
    }
    sort(carrot.begin(),carrot.end());

    for(int i = 0; i < n; i++){
        ll w = carrot[i].second;
        ll p = carrot[i].first;
        ans += w + p * (i + t - n);
    }
    cout << ans;
}