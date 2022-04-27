#include <bits/stdc++.h>
using namespace std;

int n, board[3][3];

int canWin(int r, int c){
  if(r == n-1 && c == n-1) return 1;
  if(0 > r || r >= n || 0 > c || c >= n) return 0;
  int ret = 0;
  if(r + board[r][c] > r) ret = max(ret, canWin(r + board[r][c], c));
  if(c + board[r][c] > c) ret = max(ret, canWin(r, c + board[r][c]));
  return ret;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) 
      cin >> board[i][j];

  if(canWin(0, 0)) cout << "HaruHaru";
  else cout << "Hing";
}