#include <bits/stdc++.h>
#define ll long long
using namespace std;
using pii = pair<int,int>;
ll ans;
int n, m, fenwick[2001];
vector <pii> edge;

void update(int idx, int val){
    while(idx <= n){
        fenwick[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx){
    int ret = 0;
    while(idx){
        ret += fenwick[idx];
        idx -= idx & -idx;
    }
    return ret;
}

int main(){
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        edge.emplace_back(a, b);
    }
    sort(edge.begin(), edge.end());

    for(auto e : edge){
        ans += query(n) - query(e.second);
        update(e.second, 1);
    }
    cout << ans;
}