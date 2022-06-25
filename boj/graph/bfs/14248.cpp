#include <bits/stdc++.h>
using namespace std;
int n, stone[100001], ck[100001], s, ans;

void bfs(){
  ck[s] = 1;
  queue <int> q;
  q.push(s);

  while(!q.empty()){
    int x = q.front();
    q.pop();
    
    if(1 <= x - stone[x] && !ck[x - stone[x]]) {
      ck[x - stone[x]] = 1;
      q.push(x - stone[x]);
    }

    if(x + stone[x] <= n && !ck[x + stone[x]]) {
      ck[x + stone[x]] = 1;
      q.push(x + stone[x]);
    }
  }
}

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> stone[i];
  cin >> s;
  bfs();
  for(int i = 1; i <= n; i++) 
    if(ck[i]) 
      ans++;
  cout << ans;
}
