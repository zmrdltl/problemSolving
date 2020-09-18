#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,t[10001],ind[10001],minTime[10001],workn,pwork,ans;
vector <int> a[10001];

int main() {
	queue <int> q;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> t[i];
		cin >> workn;
		for (int j = 0; j < workn; j++){
			cin >> pwork;
			a[pwork].push_back(i);
			ind[i]++;
		}
	}

	for (int i = 1; i <= n; i++){
		if (ind[i] == 0){
			q.push(i);
			minTime[i] = t[i];
		}

	}

	for (int k = 1; k <= n; k++){
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++){
			int y = a[x][i];
			ind[y]--;
			if (minTime[y] < minTime[x] + t[y])//최소 작업 시간을 저장한다
				minTime[y] = minTime[x] + t[y];
			if (ind[y] == 0) { q.push(y); }
		}
	}
	for (int i = 1; i <= n; i++) {
		if (minTime[i] > ans)
			ans = minTime[i];
	}
	cout << ans << '\n';
}