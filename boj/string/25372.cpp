#include <bits/stdc++.h>
using namespace std;

int n, sz;
string s;

int main(){
  cin >> n;
  while(n--){
    cin >> s;
    sz = s.size();
    if(6 <= sz && sz <= 9) cout << "yes\n";
    else cout << "no\n";
  }
}