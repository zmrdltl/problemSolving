#include <bits/stdc++.h>
using namespace std;
int daughter, remainMedal, di, minAns;
int main(){
  cin >> daughter >> remainMedal;
  di = remainMedal / (daughter-1);
  minAns = remainMedal + di;
  if(remainMedal - di * (daughter-1) == 0) cout << minAns - 1 << ' ' << minAns << '\n';
  else cout << minAns << ' ' << minAns;
}