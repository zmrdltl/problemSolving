#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main(){
  cin >> n;
  for(int i = 1; i <= n; i++) ans += pow(i,3);
  cout << ans;
}