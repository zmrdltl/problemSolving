#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x,y;
};
vector <Point> v;
int n;
double ans;
int main(){
  cin >> n;
  v.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i].x >> v[i].y;
  }
  for(int i = 0; i < v.size(); i++) {
    double len;
    if(!i) len = sqrt(pow(v[0].x - v[n-1].x, 2) + pow(v[0].y - v[n-1].y, 2));
    else   len = sqrt(pow(v[i].x - v[i-1].x, 2) + pow(v[i].y - v[i-1].y, 2));
    ans += len;
  }
  cout << ans;
}