#include <bits/stdc++.h>
using namespace std;
int chicken, coke, beer;
int main(){
  cin >> chicken >> coke >> beer;
  cout << min(chicken, coke / 2 + beer);
}