#include <bits/stdc++.h>
using namespace std;
int y;
double h;

int backtracking(double h, int y){
  if(y < 0) return 0;
  if(y == 0) return h;
  int ret = 0;
  ret = max(ret, dp((int)h * 1.05, y - 1));
  ret = max(ret, dp((int)h * 1.2, y - 3));
  ret = max(ret, dp((int)h * 1.35, y - 5));

  return ret;
}

int main(){
  cin >> h >> y;
  cout << backtracking(h, y);
}