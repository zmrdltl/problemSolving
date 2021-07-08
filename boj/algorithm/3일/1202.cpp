#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
multiset<int>bags;
int main(){
	int n, k;
	cin>> n >> k;
	vector <pii> gem (n); //가치 , 무게 
	for(int i=0; i<n; i++){
		cin>>gem[i].second>>gem[i].first;
	}
	for(int i=0; i<k; i++){
		int temp;
		cin>>temp;
		bags.insert(temp);
	}
	sort(gem.rbegin(),gem.rend());
	ll ans = 0;
	multiset<int>::iterator it;
	for(int i = 0; i < gem.size(); i++){
		int v = gem[i].first;
		int w = gem[i].second;
		it = bags.lower_bound(w);
		if(it != bags.end()){
			ans += v;
			bags.erase(it);
		}
	}
	cout << ans;
}