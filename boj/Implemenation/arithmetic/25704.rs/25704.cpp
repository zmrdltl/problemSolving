#include <bits/stdc++.h>
using namespace std;
double n, p, ans;

int getSaledPrice(){
  if(n < 5) return p;
  if(n < 10) return p - 500;
  if(n < 15) return min(p - 500, p * 0.9);
  if(n < 20) return min({p - 500, p * 0.9, p - 2000});
  return min({p - 500, p * 0.9, p - 2000, p * 0.75});
}

int main(){
  cin >> n >> p;
  ans = getSaledPrice();
  if(ans < 0) ans = 0;
  cout << ans << '\n';
}