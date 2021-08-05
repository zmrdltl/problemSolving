#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, k;
vector <int> v, tree;

int convert(int num){
    if(num < 0) return -1;
    else if(num > 0) return 1;
    return 0;
}

int init(int start, int end, int node){
    if(start == end) return tree[node] = convert(v[start]);
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1);
}

int mul(int start, int end, int node, int left, int right){
    if(end < left || start > right) return 1;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return mul(start, mid, node * 2, left, right) * mul(mid + 1, end, node * 2 + 1, left, right);
}

int update(int start, int end, int node, int index, int num){
    if(start > index || index > end) return tree[node];
    if(start == end) return tree[node] = convert(num);

    int mid = (start + end) / 2;
    return tree[node] = 
    update(start, mid, node * 2, index, num) *
    update(mid + 1, end, node * 2 + 1, index, num);
}

int main(){
    fastio;
    while(cin >> n >> k){
        v.resize(n);
        tree.resize(4*n);
        for(int i = 0; i < n; i++) cin >> v[i];

        init(0,n-1,1);

        for(int i = 0; i < k; i++){
            char op;
            int a,b;
            cin >> op >> a >> b;
            if(op == 'C' ) update(0, n-1, 1,a-1,b);
            else {
                int result = mul(0,n-1,1,a-1,b-1);
                if(result == 0) cout << '0';
                else if(result > 0) cout << '+';
                else cout << '-';
            }
        }
        
        cout << '\n';
    }

}