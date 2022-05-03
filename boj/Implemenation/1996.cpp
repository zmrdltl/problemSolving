#include <bits/stdc++.h>
using namespace std;

int n;
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
char board[1001][1001], ans[1001][1001];

int main(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> board[i];

  for(int r = 0; r < n; r++){
    for(int c = 0; c < n; c++){

      if(board[r][c] != '.') { ans[r][c] = '*'; continue; }
      int cnt = 0;

      for(int i = 0; i < 8; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(0 > nr || nr >= n || 0 > nc || nc >= n) continue;
        if(board[nr][nc] == '.') continue;
        cnt += board[nr][nc] - '0';
      }

      if(cnt >= 10) ans[r][c] = 'M';
      else ans[r][c] = cnt + '0';
    }
  }

  for(int i = 0; i < n; i++) cout << ans[i] << '\n';
}