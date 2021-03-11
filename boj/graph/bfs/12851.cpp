#include <iostream>
#include <queue>
using namespace std;
int c[100001], n, k, t;
queue <int> q;
//i에 도착하는 경우의 수 d[i];
int bfs()
{
	q.push(n);
	c[n] = 1;
	while (!q.empty()){
		int x = q.front();
		q.pop();
		if (x == k) return c[x] - 1;
		if (x - 1 >= 0 && !c[x - 1]) {
            c[x - 1] = c[x] + 1; 
            q.push(x - 1); 
        }
		if (x + 1 <= 100000 && !c[x + 1]) { 
            c[x + 1] = c[x] + 1; 
            q.push(x + 1); 
        }
		if (2 * x <= 100000 && !c[2 * x]) {
            c[2 * x] = c[x] + 1; 
            q.push(2 * x); 
        }
	}
}

int main() {
	cin >> n >> k;
	t = bfs();
    int ans = 0;
    for(int i = 1; i <= 100000; i++){
        if(c[i] - 1 == k) ans++;
    }
    cout << t <<'\n';
    cout << ans <<'\n';
}