#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int penalty, curTime;
vector <pii> v(11);

int main(){
  for(int i = 0; i < 11; i++)
    cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.end());

  for(int i = 0; i < v.size(); i++){
    penalty += (curTime + v[i].first + 20 * v[i].second);
    curTime += v[i].first;
  }
  cout << penalty;
}