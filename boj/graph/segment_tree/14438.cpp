#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, q, num[100001], tree[400001];

int init(int start, int end, int node){
    if(start == end) return tree[node] = num[start];
    int mid = (start + end) / 2;
    return tree[node] = min(init(start, mid, node * 2),init(mid + 1, end, node * 2 + 1));
}

int update(int start, int end, int node, int index, int num){
    if(index < start || index > end) return tree[node];
    if(start == end) return tree[node] = num;
    int mid = (start + end) / 2;

    return tree[node] = 
    min(update(start, mid, node * 2, index, num), update(mid + 1, end, node * 2 + 1, index, num));
}

int query(int start, int end, int node, int left, int right){
    if(left > end || right < start) return INF;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return min(query(start, mid, node * 2, left, right),query(mid + 1, end, node * 2 + 1, left, right));
}

int main(){
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    memset(tree,INF,sizeof(tree));
    init(0,n-1,1);    
    cin >> q;
    while(q--){
        int op,a,b;
        cin >> op >> a >> b;
        if(op == 1) update(0,n-1,1,a-1,b);
        else cout << query(0,n-1,1,a-1,b-1) << '\n';
    }
}