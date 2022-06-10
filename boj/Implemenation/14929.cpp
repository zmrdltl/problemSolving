#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, ans;
vector <ll> v, sum;

int main(){
  cin >> n;
  v.resize(n+1);
  sum.resize(n+1);
  for(int i = 1; i <= n; i++) cin >> v[i];
  for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + v[i];
  for(int i = 1; i <= n; i++)
    ans += v[i] * (sum[n] - sum[i]);
  cout << ans;
}