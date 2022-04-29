#include <bits/stdc++.h>
using namespace std;

struct Point{ double x,y; };
Point a, b, c;
double abLen, acLen, bcLen, len1, len2, len3;

double getLength(Point a, Point b){
  double x = a.x - b.x;
  double y = a.y - b.y;
  return sqrt(x*x + y*y);
}

double getInclination(Point a, Point b){
  return abs(a.y-b.y) / abs(a.x- b.x);
}

int main(){
  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
  if(getInclination(a, b) == getInclination(b, c)) {cout << "-1.0"; return 0;}

  abLen = getLength(a, b);
  bcLen = getLength(b, c);
  acLen = getLength(a, c);

  len1 = (abLen + bcLen) * 2;
  len2 = (acLen + bcLen) * 2;
  len3 = (abLen + acLen) * 2;
  
  printf("%.16f",max({len1, len2, len3}) - min({len1, len2, len3})); 
}