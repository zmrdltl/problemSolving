#include <bits/stdc++.h>
using namespace std;

struct Seg{
	int arr[2020202];
	int bias;

	void init(int n){
		memset(arr, 0, sizeof arr);
		for(bias = 1; bias < n; bias <<= 1);
	}

	void update(int x, int v){
		x |= bias;
		arr[x] = v;
		while(x >>= 1){
			arr[x] = arr[x<<1] + arr[x<<1|1];
		}
	}

	int query(int l, int r){
		l |= bias, r |= bias;
		int lval = 0, rval = 0;
		while(l <= r){
			if(l&1) lval = lval + arr[l++];
			if(!(r&1)) rval = rval + arr[r--];
			l >>= 1, r >>= 1;
		}
		return lval + rval;
	}
} tree;

typedef pair<int, int> p;
vector<p> v;

int ans[500001], n;


int main(){
    cin >> n; 
    v.resize(n); 
    tree.init(n);
	for(int i=0; i<n; i++){
		int t; cin >> t;
		v[i] = {i+1, t};
	}

	sort(v.begin(), v.end(), [&](p &a, p &b){
		return a.second < b.second;
	});

	for(auto &i : v){
		int idx = i.first;
		ans[idx] = idx - tree.query(1, idx-1);
		tree.update(idx, 1);
	}

	for(int i=1; i<=n; i++) cout << ans[i] << "\n";
}