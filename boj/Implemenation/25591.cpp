#include <bits/stdc++.h>
using namespace std;
int n1, n2, a, b, c, d, q, r;
int main(){
  cin >> n1 >> n2;
  a = 100 - n1;
  b = 100 - n2;
  c = 100 - (a + b);
  d = a * b;
  q = d / 100;
  r = d % 100;
  cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << q << ' ' << r << '\n';
  cout << c + q << ' ' << r << '\n';
}