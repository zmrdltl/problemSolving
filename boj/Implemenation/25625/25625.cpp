#include <bits/stdc++.h>
using namespace std;
int x, y;
int main(){
  cin >> x >> y;
  if(x > y) {
    cout << x + y;
  }
  else {
    cout << y - x;
  }
}