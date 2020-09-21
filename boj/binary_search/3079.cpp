#include <iostream>
#include <algorithm>
#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll n,m;
ll times[100001];
ll MAX;
ll binarySearch(){
    ll ansTime = MAX * m;

    ll l = 1;
    ll r = MAX * m;
    while(l<=r){
        ll mid = (l+r)/2;
        ll sum  =0;
        for(ll i = 0; i < n; i++){
            sum += mid / times[i];
        }
        if(sum >= m){
            ansTime = min(ansTime,mid);
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return ansTime;
}
int main(){
    fastio;
    cin >> n >> m;
    for(ll i = 0; i < n; i++){
        cin >> times[i];
        MAX = max(MAX,times[i]);
    }
    sort(times,times+n);
    cout << binarySearch() << '\n';
}