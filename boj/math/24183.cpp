#include <bits/stdc++.h>
using namespace std;
double c4, a3, a4, envelop, poster, sheet;
int main(){
  cin >> c4 >> a3 >> a4;
  envelop = 229 * 324 * c4 * 2;
  poster = 297 * 420 * a3 * 2;
  sheet = 210 * 297 * a4;
  
  printf("%.6f", (envelop + poster + sheet) * 0.000001);
}