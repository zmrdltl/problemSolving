#include <bits/stdc++.h>
using namespace std;

int r, c, ans;
char ori[101][101];

int main(){
  cin >> r >> c;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cin >> ori[i][j];
    }
  }
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      char x;
      cin >> x;
      if(ori[i][j] == x) ans++;
    }
  }
  cout << ans;
}