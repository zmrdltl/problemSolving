#include <bits/stdc++.h>
using namespace std;
int n, score;
string s;
int main(){
  cin >> n;
  cin.ignore();
  while(n--){
    score = 0;
    getline(cin, s);
    for(auto c : s){
      if(c == ' ') continue;
      score += c - 'A' + 1;
    }
    if(score == 100) cout << "PERFECT LIFE\n";
    else cout << score << '\n';
  }
}