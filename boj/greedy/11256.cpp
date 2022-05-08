#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int t, ans, candyNum, boxNum, sum, cnt;

bool cmp(pii a, pii b){
  return a.first * a.second > b.first * b.second;
}

int main(){
  cin >> t;
  while(t--){
    sum = 0, cnt = 0;
    cin >> candyNum >> boxNum;
    vector <pii> v(boxNum);
    for(int i = 0; i < boxNum; i++) cin >> v[i].first >> v[i].second;
    
    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < boxNum; i++){
      sum += v[i].first * v[i].second;
      cnt++;
      if(sum >= candyNum) break;
    }
    cout << cnt << '\n';
  }
}