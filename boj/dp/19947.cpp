#include <bits/stdc++.h>
using namespace std;
int y;
double h;

int bruteForce(double money, int year){
  if(year > y) return 0;
  if(year == y) return money;
  int ret = 0;
  ret = max(ret, bruteForce((int)money * 1.05, year + 1));
  ret = max(ret, bruteForce((int)money * 1.2, year + 3));
  ret = max(ret, bruteForce((int)money * 1.35, year + 5));

  return ret;
}

int main(){
  cin >> h >> y;
  cout << bruteForce(h, 0);
}