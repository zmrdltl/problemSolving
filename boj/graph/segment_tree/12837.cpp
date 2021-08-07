#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
ll days[1000001], tree[4000001], q, n;

void update(int start, int end, int node, int index, int diff){
    if(index < start || index > end) return;
    tree[node] += diff;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, diff);
    update(mid + 1, end, node * 2 + 1, index, diff);
}

ll sum(int start, int end, int node, int left, int right){
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

int main(){
    fastio;
    cin >> n >> q;
    while(q--) {
        ll a,b,c;
        cin >> a >> b >> c;
        if(a == 1) update(1,n,1,b,c);            
        else cout << sum(1,n,1,b,c) << '\n';
    }
}