#include <bits/stdc++.h>
using namespace std;

int n, x;
vector <int> v;

int main(){
  cin >> n;
  v.resize(n+1);
  for(int i = 1; i <= n; i++){
    cin >> x;
    v[x] = i;
  }

  for(int i = 1; i < v.size(); i++){
    cout << v[i] << '\n';
  }
}