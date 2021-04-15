#include <bits/stdc++.h>
using namespace std;

int N, cnt;
int A[1001], dp[1001];
vector<int> v, ans;

int main(){
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	v.push_back(A[1]);
	for (int i = 2; i <= N; i++){
		if (v[cnt] < A[i]){
			v.push_back(A[i]);
			dp[i] = ++cnt;
		}
		else
		{
			int pos = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
			v[pos] = A[i];
			dp[i] = pos;
		}
	}
	for (int i = N; i >= 0; i--){
		if (dp[i] == cnt){
			ans.push_back(A[i]);
			cnt--;
		}
	}
    int size = ans.size();
	cout << size << '\n';
	for (int i = 0; i < size; i++){
		cout << ans.back() << " ";
		ans.pop_back();
	}
}