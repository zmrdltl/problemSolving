#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, length, ans;
vector <ll> v;

int main(){
  cin >> n;
  v.resize(n);
  for(int i = 0; i < n; i++) cin >> v[i], length += v[i];
  for(int i = 0; i < n; i++){
    ans += v[i] * (length - v[i]);
    length -= v[i];
  }
  cout << ans;
}