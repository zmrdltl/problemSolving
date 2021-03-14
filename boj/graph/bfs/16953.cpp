#include <bits/stdc++.h>
#define ll long long
using namespace std;
using pll = pair <ll,ll>;
ll a,b;

int bfs(){
    ll ans = 0x7f7f7f7f;
    queue <pll> q;
    q.push({a,1});
    while(!q.empty()){
        ll x = q.front().first;
        ll cnt = q.front().second;
        ll plusOne = x * 10 + 1;
        q.pop();
        if(x == b) ans = min (ans,cnt);
        if(x * 2 <= b ) q.push({x * 2, cnt + 1});
        if(plusOne <= b ) q.push({plusOne, cnt + 1});
        cnt++;
    }
    if(ans == 0x7f7f7f7f) return -1;
    return ans;
}

int main(){
    cin >> a >> b;
    cout << bfs();
}
