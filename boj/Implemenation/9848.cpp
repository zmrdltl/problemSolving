#include <bits/stdc++.h>
using namespace std;
int n, k, ans, record, prevRecord;
int main(){
  cin >> n >> k;
  while(n--){
    cin >> record;
    if(prevRecord - record >= k) ans++;
    prevRecord = record;
  }
  cout << ans;
}