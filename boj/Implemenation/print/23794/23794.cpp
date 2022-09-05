#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
  cin >> n;
  for(int i = 0; i < n + 2; i++) cout << '@';
  cout << '\n';
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n + 2; j++){
      if(j == 0 || j == n + 1) cout << '@';
      else cout << ' ';
    }
    cout << '\n';
  }
  for(int i = 0; i < n + 2; i++) cout << '@';
}