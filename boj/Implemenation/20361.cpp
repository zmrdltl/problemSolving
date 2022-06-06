#include <bits/stdc++.h>
using namespace std;

int n, ballPos, k, ans;
vector <int> cups;

int main(){
  cin >> n >> ballPos >> k;
  cups.resize(n+1);

  for(int i = 1; i <= n; i++){
    cups[i] = i;
  }

  for(int i = 0, a, b; i < k; i++){
    cin >> a >> b;
    swap(cups[a], cups[b]);
  }
  for(int i = 1; i <= n; i++){
    if(cups[i] == ballPos) {
      ans = i;
      break;
    }
  }

  cout << ans;
}