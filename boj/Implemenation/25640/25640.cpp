#include <bits/stdc++.h>
using namespace std;
string jinhoMBTI, friendMBTI;
int n, ans;
int main(){
  cin >> jinhoMBTI >> n;
  while(n--){
    cin >> friendMBTI;
    if(jinhoMBTI == friendMBTI) ans++;
  }
  cout << ans;
}