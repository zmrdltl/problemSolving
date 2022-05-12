#include <bits/stdc++.h>
using namespace std;

int n, length, ans;
vector <string> students;
map <string, int> m;

bool isDuplicated(){
  for(auto el : m)
    if(el.second > 1) 
      return true;
  return false;
}

int main(){
  cin >> n;
  students.resize(n);
  for(int i = 0; i < n; i++) cin >> students[i];
  length = students[0].size();
  ans = length;
  for(int k = 0; k < length; k++){
    m.clear();
    for(int i = 0; i < n; i++) m[students[i].substr(k)]++;
    if(!isDuplicated()) ans = min(ans, length - k);
  }
  cout << ans;
}