#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
  cin >> n;
  for(int i = 0; i < n*5 - n; i++) {
    for(int j = 0; j < n; j++)
      cout << '@';
    cout << '\n';
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n*5; j++)
      cout << '@';
    cout << '\n';
  }
}