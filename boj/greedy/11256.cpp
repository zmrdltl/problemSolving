#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int testCase, candyNum, boxNum, sum, cnt;
vector <pii> boxes;

bool cmp(pii a, pii b){
  return a.first * a.second > b.first * b.second;
}

int main(){
  cin >> testCase;
  while(testCase--){
    cin >> candyNum >> boxNum;
    sum = 0, cnt = 0;
    boxes.resize(boxNum);
    for(int i = 0; i < boxNum; i++) cin >> boxes[i].first >> boxes[i].second;

    sort(boxes.begin(), boxes.end(), cmp);

    for(int i = 0; i < boxNum; i++){
      sum += boxes[i].first * boxes[i].second;
      cnt++;
      if(sum >= candyNum) break;
    }
    cout << cnt << '\n';
  }
}