#include <bits/stdc++.h>
using namespace std;

map <int,int> xMap, yMap;
int n, ans;

int main(){
  cin >> n;
  for(int i = 0, x, y; i < n; i++){
    cin >> x >> y;
    xMap[x]++;
    yMap[y]++;
  }
  for(auto el : xMap){
    if(el.second >= 2) ans++;
  }
  for(auto el : yMap){
    if(el.second >= 2) ans++;
  }
  cout << ans;
}