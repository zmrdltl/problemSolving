#include <bits/stdc++.h>
using namespace std;
int t, testerNum, a, b, c, totalScore;
int main(){
  cin >> t;
  while(t--){
    cin >> testerNum >> a >> b >> c;
    totalScore = a + b + c;
    cout << testerNum << ' ' << totalScore << ' ';
    if(totalScore >= 55 && a >= 11 && b >= 8 && c >= 12) cout << "PASS\n";
    else cout << "FAIL\n";
  }
}