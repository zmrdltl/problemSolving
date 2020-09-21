#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;
queue <tuple<int,int,int>> q;
int m,n,h,ans;
int tomatoBox[101][101][101];
int check[101][101][101];
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {1, -1, 0, 0, 0, 0};
int dh[] = {0, 0, 0, 0, 1, -1};
int d[101][101][101];

bool isAllRiped(){
	for(int k = 0; k < h; k ++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j ++)
				if(tomatoBox[k][i][j]==0) return 0;
	return 1;
}

int bfs(){
	int day = 0;
	while(!q.empty()){
		int height = get<0>(q.front());
		int x = get<1>(q.front());
		int y = get<2>(q.front());
		q.pop();
		for(int direction = 0; direction < 6; direction++){
			int nheight = height + dh[direction];
			int nx = x + dx[direction];
			int ny = y + dy[direction];
			if(0 > nheight || nheight >= h || 0 > nx || nx >= n || 0 > ny || ny >= m) continue;
			if(tomatoBox[nheight][nx][ny]==0 && check[nheight][nx][ny]==0){
				check[nheight][nx][ny] = 1;
				tomatoBox[nheight][nx][ny] = 1;
				q.push({nheight,nx,ny});
				d[nheight][nx][ny] = d[height][x][y] + 1;
				day = max(day,d[nheight][nx][ny]);
			}
		}
	}
	return day;
}

int main(){
	cin >> m >> n >> h;
	for(int k = 0; k < h; k ++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j ++){
				cin >> tomatoBox[k][i][j];
				if(tomatoBox[k][i][j]==1) q.push({k,i,j});
			}
		}
	}
	if(isAllRiped()) {cout << 0 <<'\n'; return 0;}
	ans = bfs();
	if(isAllRiped()) cout << ans <<'\n';
	else cout << -1 << '\n';
}