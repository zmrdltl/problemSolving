#include <bits/stdc++.h>
using namespace std;
int x, ans;
int main(){
  while(1){
    cin >> x;
    if(x == -1) break;
    ans += x;
  }
  cout << ans;
}
