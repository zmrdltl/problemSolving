#include <bits/stdc++.h>
using namespace std;
double a, b;
int main(){
  cin >> a >> b;
  if(a * (100 - b) / 100 >= 100) cout << 0;
  else cout << 1;
}