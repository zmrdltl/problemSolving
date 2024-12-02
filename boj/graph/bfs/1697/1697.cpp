#include <iostream>
#include <queue>
using namespace std;
int c[100001], N, K;
queue <int> q;
int BFS()
{
	q.push(N);
	c[N] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (x == K) { return c[x] - 1; }
		if (x - 1 >= 0 && !c[x - 1]) { c[x - 1] = c[x] + 1; q.push(x - 1); }
		if (x + 1 <= 100000 && !c[x + 1]) { c[x + 1] = c[x] + 1; q.push(x + 1); }
		if (2 * x <= 100000 && !c[2 * x]) { c[2 * x] = c[x] + 1; q.push(2 * x); }
	}
}

int main() {
	cin >> N >> K;
	cout << BFS();
}