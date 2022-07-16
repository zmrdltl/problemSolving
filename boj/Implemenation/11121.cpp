#include <bits/stdc++.h>
using namespace std;
int t;
string a, b;

string isOk(){
  for(int i = 0; i < a.size(); i++){
    if(a[i] != b[i]) return "ERROR\n";
  }
  return "OK\n";
}

int main(){
  cin >> t;
  while(t--){
    cin >> a >> b;
    cout << isOk();
  }
}