#include <bits/stdc++.h>
using namespace std;
int ans, fence[101], a[4];
int main(){
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  for(int i = a[0]; i < a[1]; i++) fence[i]++;
  for(int i = a[2]; i < a[3]; i++) fence[i]++;
  for(int i = 0; i <= 100; i++){
    if(fence[i]) ans ++;
  }
  cout << ans;
}