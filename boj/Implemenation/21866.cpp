#include <bits/stdc++.h>
using namespace std;
int score[9], limit[9] = {100, 100, 200, 200, 300, 300, 400, 400, 500}, state = 1, totalScore;
int main(){
  for(int i = 0; i < 9; i++) cin >> score[i];
  for(int i = 0; i < 9; i++){
    if(score[i] > limit[i]) state = 2;
    totalScore += score[i];
  }
  if(totalScore < 100) state = 0;
  if(totalScore >= 100 && state == 1) cout << "draw";
  else if(state == 2) cout << "hacker";
  else cout << "none";
}