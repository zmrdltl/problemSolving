#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
ll n, m, tree[4000005], a[1000005];


ll sum(int start, int end, int node, int left, int right){
    if(right < start || end < left ) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, int diff){
    if(index < start || index > end) return;
    tree[node] += diff;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, diff);
    update(mid + 1, end, node * 2 + 1, index, diff);
}

int main(){
    fastio;
    cin >> n >> m;
    while(m--) {
        ll op, i, j;
        cin >> op >> i >> j;
        if(!op) {
            if (i > j) swap(i,j);
            cout << sum(1,n,1,i,j) << '\n';
        }
        else {
            ll diff = j - a[i];
            a[i] = j;
            update(1,n,1,i,diff);
        }
    }
}