#include <bits/stdc++.h>
#define MAX 0x3f3f3f3f
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int t, n, minNum, maxNum;
int main(){
  fastio;
  cin >> t;
  while(t--){
    cin >> n;
    minNum = MAX;
    maxNum = -MAX;
    for(int i = 0,x; i < n; i++) {
      cin >> x;
      minNum = min(minNum, x);
      maxNum = max(maxNum, x);
    }
    cout << minNum << ' ' << maxNum << '\n';
  }
}