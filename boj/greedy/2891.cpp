#include <bits/stdc++.h>
using namespace std;

int n, s, r, kayak[12], ans;

int main(){
  cin >> n >> s >> r;

  for(int i = 1; i <= n; i++) {
    kayak[i] = 1;
  }

  for(int i = 0, teamNum; i < s; i++) {
    cin >> teamNum;
    kayak[teamNum]--;
  }

  for(int i = 0, teamNum; i < r; i++) {
    cin >> teamNum;
    kayak[teamNum]++;
  }

  for(int i = 1; i <= n; i++) {
    if(kayak[i] != 2) {
      continue;
    }
    if(!kayak[i-1]) {
      kayak[i] = kayak[i-1] = 1;
      continue;
    }
    if(!kayak[i+1]) {
      kayak[i] = kayak[i+1] = 1;
    }
  }

  for(int i = 1; i <= n; i++)
    if(!kayak[i])
      ans++;

  cout << ans;
}