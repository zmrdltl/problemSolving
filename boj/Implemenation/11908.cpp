#include <bits/stdc++.h>
using namespace std;

int n, sum;
vector <int> v;

int main(){
  cin >> n;
  v.resize(n);

  for(int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());

  for(int i = 0; i < v.size() - 1; i++) sum += v[i];
  cout << sum;
}