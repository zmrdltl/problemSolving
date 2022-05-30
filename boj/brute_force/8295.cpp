#include <bits/stdc++.h>
using namespace std;
int n, m, p, ans;
int main(){
  cin >> n >> m >> p;
  for(int height = 1; height <= n; height++){
    for(int width = 1; width <= m; width++){
      int perimeter = (height + width) * 2;
      if(perimeter < p) continue;
      ans += (n - height + 1) * (m - width + 1);
    }
  }
  cout << ans;
}