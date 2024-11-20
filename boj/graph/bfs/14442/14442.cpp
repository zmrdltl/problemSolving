#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<vector<int>> map_input;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int bfs() {
  queue<tuple<int, int, int>> q;
  q.push({0, 0, 0});
  
  vector<vector<vector<int>>> check(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));
  check[0][0][0] = 1;
  
  while (!q.empty()) {
    auto [r, c, break_cnt] = q.front();
    q.pop();
    
    if (r == n - 1 && c == m - 1) {
      return check[r][c][break_cnt];
    }
    
    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      
      if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
        continue;
      }
      
      if (map_input[nr][nc] == 0 && check[nr][nc][break_cnt] == 0) {
        check[nr][nc][break_cnt] = check[r][c][break_cnt] + 1;
        q.push({nr, nc, break_cnt});
      }
      
      if (map_input[nr][nc] == 1 && break_cnt < k && check[nr][nc][break_cnt + 1] == 0) {
        check[nr][nc][break_cnt + 1] = check[r][c][break_cnt] + 1;
        q.push({nr, nc, break_cnt + 1});
      }
    }
  }
  
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n >> m >> k;
  map_input.resize(n, vector<int>(m));
  
  for (int i = 0; i < n; i++) {
    string line;
    cin >> line;
    for (int j = 0; j < m; j++) {
      map_input[i][j] = line[j] - '0';
    }
  }
  
  cout << bfs() << "\n";
  return 0;
}
