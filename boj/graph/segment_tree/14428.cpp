#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
struct Node { int num = INF, idx = INF; };
int n, q, a[100001];
vector <Node> tree(400001);

bool operator < (const Node &a, const Node &b){
    if(a.num == b.num) return a.idx < b.idx;
    return a.num < b.num;
}

Node query(int start, int end, int node, int left, int right){
    if(left > end || start > right) return {INF, INF};
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return min(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
}

Node update(int start, int end, int node, int index, int y){
    if(index < start || index > end) return tree[node];
    if(start == end) return tree[node] = {y, index};
    int mid = (start + end) / 2;
    return tree[node] = min(
        update(start, mid, node * 2, index, y),
        update(mid + 1, end, node * 2 + 1, index, y)
    );
}

Node init(int start, int end, int node){
    if(start == end) return tree[node] = {a[start], start};
    int mid = (start + end) / 2;
    return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int main(){
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> q;
    init(0,n-1,1);
    while(q--){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1){
            update(0,n-1,1,x-1,y);
        }else{
            cout << query(0,n-1,1,x-1,y-1).idx + 1<< '\n';
        }
    }
}