#include <bits/stdc++.h>
using namespace std;
double a, b, m;
int main(){
  cin >> a >> b;
  m = (b - a) / 400;
  printf("%.20f", 1 / (1 + pow(10, m)));
}