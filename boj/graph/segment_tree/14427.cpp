#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
struct Node { int num = INF, idx = INF; };
int nums[100001], n, k, q;
vector <Node> tree(400001);

bool operator < (const Node &a, const Node &b){
    if(a.num == b.num) return a.idx < b.idx;
    return a.num < b.num;
}

Node init(int start, int end, int node){
    if(start == end) return tree[node] = {nums[start], start};
    int mid = (start + end) / 2;
    return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}


Node update(int start, int end, int node, int index, int num){
    if(index < start || end < index) return tree[node];
    if(start == end) return tree[node] = {num, index}; 

    int mid = (start + end) / 2;

    return tree[node] = min(
        update(start, mid, node * 2, index, num),
        update(mid + 1, end, node * 2 + 1, index, num)
    );
}

Node query(int start, int end, int node, int left, int right){
    if(end < left || start > right) return {INF, INF};
    if(left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;

    return min(
        query(start, mid, node * 2, left, right),
        query(mid + 1, end, node * 2 + 1, left, right)
    );
}

int main(){
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> nums[i];
    cin >> q;
    init(0,n-1,1);
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int a, b;
            cin >> a >> b;
            update(0,n-1,1,a-1,b);
        }
        else{
            Node ans = query(0,n-1,1,0,n-1);
            cout << ans.idx + 1 << '\n';
        }
    }

}