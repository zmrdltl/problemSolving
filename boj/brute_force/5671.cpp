#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int main(){
  while(cin >> n >> m){
    ans = 0;
    for(int i = n; i <= m; i++){

      string room = to_string(i);
      vector <int> cnt(10,0);
      bool isValid = true;

      for(int i = 0; i < room.size(); i++)
        cnt[room[i] - '0']++;

      for(int i = 0; i < 10; i++)
        if(cnt[i] >= 2) {isValid = false; break;}

      if(isValid) ans++;
    }
    cout << ans << '\n';
  }
}