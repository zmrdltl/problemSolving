#include <iostream>
#include <queue>
using namespace std;
int N, M, h, w,d[1000][1000], a[1000][1000], dh[] = { 0,0,-1,1 }, dw[] = { -1,1,0,0 }, ans,cnt;
queue <pair <int, int>> q;
int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> a[i][j];
			d[i][j] = -1;
			if (a[i][j] == 1)//이미 익어있는 상태라면 큐에 넣어줌 -> 먼저 들어가 있는(익어있는) 큐(토마토)의 요소 부터 탐색하기 위함
			{
				q.push(make_pair(i, j));
				d[i][j] = 0;//익어 있는 토마토로부터의 거리는 0이므로 초기화해 줌
			}
		}
	for (int i = 0; i < N; i++)//모두 익어있는 상태면 0출력
		for (int j = 0; j < M; j++)
		{
			if (a[i][j] == 1) { cnt++; }
			if (cnt == N*M) { cout << "0"; return 0; }
		}
	//BFS탐색
	while (!q.empty())
	{
		h = q.front().first;
		w = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nh = h + dh[i];
			int nw = w + dw[i];
			if (0 <= nh && nh< N && 0 <= nw&&nw<M)
				if (a[nh][nw] == 0 && d[nh][nw] == -1)//아직 익지 않았을 때
				{
					q.push(make_pair(nh, nw));
					d[nh][nw] = d[h][w] + 1;
					ans = d[nh][nw];
				}
		}
	}
	//상자안에 토마토가 모두 익어있지 않다면 -1 출력
	for(int i = 0; i<N; i++)
		for(int j = 0; j<M; j++)
			if (a[i][j]==0&&d[i][j]==-1) { cout << "-1"; return 0; }
	/*for (int i = 0; i < N; i++, puts(""))//d출력
		for (int j = 0; j < M; j++)
			cout << d[i][j] << ' ';*/
	cout << ans << '\n';
}