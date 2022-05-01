#include <bits/stdc++.h>
using namespace std;
int n, m, ans;

bool isValid(string room){
  vector <int> cnt(10,0);
  for(int i = 0; i < room.size(); i++)
    cnt[room[i] - '0']++;
  for(int i = 0; i < 10; i++)
    if(cnt[i] >= 2) return false;
  return true;
}

int main(){
  while(cin >> n >> m){
    ans = 0;
    for(int i = n; i <= m; i++){
      string room = to_string(i);
      if(isValid(room)) ans++;
    }
    cout << ans << '\n';
  }
}