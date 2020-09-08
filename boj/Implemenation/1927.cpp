#include <iostream>
#include <queue>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int main() {
    fastio;
	priority_queue<int, vector<int>, greater<int>> q;//가장 작은 값을 front에 넣기 위해 우선 순위 큐 선언
	int n;
	cin >> n;
	while (n--){
		int x;
		cin >> x;
		if (x == 0){
			if (q.empty()) cout << 0 << '\n';
			else cout << q.top() << '\n', q.pop();
		}
		else q.push(x);
	}
}