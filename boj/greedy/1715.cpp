#include <bits/stdc++.h>
using namespace std;
int n, card;
int main(){
	int ans = 0;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for (int i = 0; i < n; i++){
		cin >> card;
		minHeap.push(card);
	}

	for (int i = 0; i < n - 1; i++){
		card = minHeap.top();
		minHeap.pop();
		card += minHeap.top();
		minHeap.pop();
		ans += card;
		minHeap.push(card);
	}
	cout << ans;
}