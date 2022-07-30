#include <bits/stdc++.h>
using namespace std;
int t, a, b, res;
char op, eq;

int getActualResult(){
  if(op == '+') return a + b;
  if(op == '-') return a - b;
}

int main(){
  cin >> t;
  for(int i = 1; i <= t; i++){
    cin >> a >> op >> b >> eq >> res;
    cout << "Case "<< i << ": ";
    if(getActualResult() == res) cout << "YES\n";
    else cout << "NO\n";
  }
}