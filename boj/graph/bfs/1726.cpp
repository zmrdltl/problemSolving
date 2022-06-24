#include <bits/stdc++.h>
using namespace std;
int dr[] = {0, -1, 0, 1}; //동 남 서 북
int dc[] = {-1, 0, 1, 0};
int factory[101][101], moved[101][101][5], n, m;
struct Robot{ int r, c, d; };
Robot start, dest;

int bfs(){
  queue <Robot> q;
  moved[start.r][start.c][start.d] = 0;
  q.push({start.r, start.c, start.d});
  while(!q.empty()){
    int r = q.front().r;
    int c = q.front().c;
    int d = q.front().d;
    q.pop();
    if(r == dest.r && c == dest.c && d == dest.d) return moved[r][c][d];
    for(int i = 1; i <= 3; i++){
      int nr = r + dr[d]*i;
      int nc = c + dc[d]*i;
      if(1 > nr || nr > n || 1 > nc || nc > m) continue;
      if(factory[nr][nc]) break;
      if(moved[nr][nc][d] >= 0) continue;
      moved[nr][nc][d] = moved[r][c][d] + 1;
      q.push({nr, nc, d});
    }

    int nd = (d + 1) % 4;
    if(moved[r][c][nd] == -1){
      moved[r][c][nd] = moved[r][c][d] + 1;
      q.push({r, c, nd});
    }
    nd = (d + 3) % 4;
    if(moved[r][c][nd] == -1){
      moved[r][c][nd] = moved[r][c][d] + 1;
      q.push({r, c, nd});
    }
  }
  return 0;
}

void setDirection(Robot &rob){
  if(rob.d == 1) rob.d = 2;
  else if(rob.d == 2) rob.d = 0; 
  else if(rob.d == 3) rob.d = 3; 
  else rob.d = 1;
}

int main(){
  memset(moved, -1, sizeof(moved));
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      cin >> factory[i][j];

  cin >> start.r >> start.c >> start.d;
  cin >> dest.r >> dest.c >> dest.d;

  setDirection(start);
  setDirection(dest);

  cout << bfs();
}
