#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ability[200001], d[200001][2], n;
vector <ll> graph[200001];
ll treeDp(ll num, ll stat){
    ll &ret = d[num][stat];
    if(ret != -1) return ret;
    ret = 0;

    //num사원이 멘토를 가지고 있다면 num의 부사수들은 num과 멘토링 못함
    if(stat) {
        for(auto next : graph[num]) ret += treeDp(next,0);
    }

    //num사원이 멘토를 가지고 있지 않다면 num의 부사수 중 한명이 num과 멘토링하거나 아예 안할 수 있음
    else {
        ll mentiNot = 0, menti = 0;
        for(auto next : graph[num]) mentiNot += treeDp(next, 0);
        ret = max(ret, mentiNot);
        for(auto next : graph[num]){
            ll synergy = ability[next] * ability[num];
            menti = mentiNot - treeDp(next,0) + treeDp(next, 1) + synergy;
            ret = max(ret, menti);
        }
    }
    return ret;
}

int main(){
    memset(d, -1, sizeof(d));
    cin >> n;
    for(int i = 2, x; i <= n; i++) {
        cin >> x;
        graph[x].push_back(i);
    }
    
    for(int i = 1; i <= n; i++) cin >> ability[i];
    cout << treeDp(1, 0);
}