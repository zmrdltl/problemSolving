#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
//TODO 못함
int m,n,h;
int tomato[101][101][101];
int ck[101][101][101];
int dx[4] ={0,0,-1,1};
int dy[4] = {-1,1,0,0};
int dz[2] = {1,-1};
int ans = 0x7f7f7f7f;
int cnt = 0;
int bfs(int h,int i,int j){
	queue <tuple<int,int,int>> q;
	memset(ck,0,sizeof(ck));
	q.push({h,i,j});
	ck[h][i][j] = 1;

	while(!q.empty()){
		auto front = q.front();
		int x = get<0>(front);
		int y = get<1>(front);
		int z = get<2>(front);
		q.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(tomato[z][nx][ny]==-1)continue;
			if(!ck[z][nx][ny] && (tomato[z][nx][ny]==1 || tomato[z][nx][ny] == 0)){
				ck[z][nx][ny] = 1;
				tomato[z][nx][ny]=1;
				q.push({z,nx,ny});
			}
		}
		if(!ck[z+1][x][y] && z+1<n && 
		(tomato[z-1][x][y]==1 || tomato[z-1][x][y]==0)) {ck[z+1][x][y] =1;tomato[z+1][x][y]=1;q.push({z+1,x,y});}

		if(!ck[z-1] && z-1 >= 0 && 
		(tomato[z-1][x][y]==1 || tomato[z-1][x][y]==0)) {ck[z-1][x][y] =1;tomato[z-1][x][y]=1;q.push({z-1,x,y});}
		
	}
	int answer = 0;
	for(int i = 0; i < h; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < m; k++)
				if(tomato[i][j][k]==1) answer++;
	if(answer<cnt) return -1;
	else return answer;
}

int main(){
	cin >> m >> n >> h;
	int cnt2= 0;
	for(int i = 0; i < h; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < m; k++){
				cin >> tomato[h][n][m];
				if(tomato[i][j][k]!=-1) cnt++;
				if(tomato[i][j][k]==1) cnt2++;
			}
	if(cnt==cnt2){cout << 0 <<'\n'; return 0;}

	for(int i = 0; i < h; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < m; k++)
				if(tomato[i][j][k]==1 && !ck[i][j][k]) ans = min(ans,bfs(i,j,k));
	for(int i = 0; i < h; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				cout << tomato[i][j][k] << ' ';
			}
			cout << '\n';
		}
	}
		

	cout << ans <<'\n';
}