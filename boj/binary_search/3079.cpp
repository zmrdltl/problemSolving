#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, MAX;
ll times[100001];
ll binarySearch(){
    ll ansTime = MAX * m;
    ll l = 1;
    ll r = MAX * m;
    while(l<=r){
        ll mid = (l + r) / 2;
        ll sum = 0;
        for(ll i = 0; i < n; i++) sum += mid / times[i];
        if(sum >= m) r = mid - 1, ansTime = min(ansTime, mid);
        else l = mid + 1;
    }
    return ansTime;
}

int main(){
    cin >> n >> m;
    for(ll i = 0; i < n; i++){
        cin >> times[i];
        MAX = max(MAX,times[i]);
    }
    sort(times,times+n);
    cout << binarySearch() << '\n';
}