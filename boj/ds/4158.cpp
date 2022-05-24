#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, m, ans;
unordered_map <int,int> sangeunCD;

int main(){
  fastio;
  while(1){
    cin >> n >> m;
    if(!n && !m) break;

    ans = 0;
    sangeunCD.clear();

    for(int i = 0, cd; i < n; i++) {
      cin >> cd;
      sangeunCD[cd] = 1;
    }

    for(int i = 0, sunyoungCD; i < m; i++) {
      cin >> sunyoungCD;
      if(sangeunCD[sunyoungCD]) ans++;
    }
    
    cout << ans << '\n';
  }
}