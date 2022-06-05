#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int r, c;
char board[101][101], ans[101][101];

void printAns(){
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cout << ans[i][j];
    }
    cout << '\n';
  }
}

void inputBoard(){
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cin >> board[i][j];
    }
  }
}

char getMineNum(int start, int end){
  int cnt = 0;
  for(int ri = start - 1; ri <= start + 1; ri++){
    for(int cj = end - 1; cj <= end + 1; cj++){
      if(0 > ri || ri >= r || 0 > cj || cj >= c) continue;
      if(board[ri][cj] =='*') cnt++;
    }
  }
  return cnt + '0';
}

void makeAns(){
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(board[i][j] == '*') {
        ans[i][j] = '*';
        continue;
      }
      ans[i][j] = getMineNum(i,j);
    }
  }
}

int main(){
  fastio;
  while(1){
    cin >> r >> c;
    if(!r && !c) break;
    inputBoard();
    makeAns();
    printAns();
  }
}