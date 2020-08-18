#include <iostream>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <queue>
using namespace std;

int n,ans = 0x7f7f7f7f;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int mapOrigin[100][100];
int mapCopy[100][100];
int ck[100][100];
int islandCnt = 0;

void bfsDistance() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mapCopy[i][j] != 0) {
				int areaNum = mapCopy[i][j];
				queue<tuple<int, int, int>> q;
                q.push({i, j, 1});
				ck[i][j] = 1;
				while (!q.empty()) {
					auto pos = q.front(); 
                    q.pop();
					int x = get<0>(pos);
					int y = get<1>(pos);
					int depth = get<2>(pos);
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue; //n 범위 넘어갈 경우
						if (mapCopy[nx][ny] == areaNum || ck[nx][ny] == 1) continue; //같은 섬인 경우
						if (mapCopy[nx][ny] != 0 ) { //다른 섬에 도착했을 때
							ans = min(ans, depth - 1);
							while (!q.empty()) q.pop();
							break;
						}
						ck[nx][ny] = 1;
						q.push({nx, ny, depth + 1});
					}
				}
				memset(ck, 0, sizeof(ck));
			}
		}
	}
}

//섬 별로 번호를 메긴다.
void bfsCopy(){
    for(int i = 0 ;i <n; i++){
        for(int j = 0; j <n; j++){
            if(mapOrigin[i][j] && !ck[i][j]){
                islandCnt++;
                queue <pair<int,int>> q;
                q.push({i,j});
                ck[i][j] = 1;
                mapCopy[i][j] = islandCnt;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int i = 0; i < 4; i++){
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
                        if(ck[nx][ny]==0 && mapOrigin[nx][ny]){
                            q.push({nx,ny});
                            ck[nx][ny] = 1;
                            mapCopy[nx][ny] = islandCnt;
                        }
                    }
                }
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i<n; i++)
        for(int j = 0 ; j < n; j++)
            cin >> mapOrigin[i][j];
    bfsCopy();
    bfsDistance();
    cout << ans <<'\n';
}