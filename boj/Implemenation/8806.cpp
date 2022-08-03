#include <bits/stdc++.h>
using namespace std;

double z, adam[3], gosia[3], a, b;

int main(){
  cin >> z;
  while(z--){
    cin >> adam[0] >> adam[1] >> adam[2];
    cin >> gosia[0] >> gosia[1] >> gosia[2];
    a = adam[0] * gosia[1] + adam[1] * gosia[2] + adam[2] * gosia[0];
    b = gosia[0] * adam[1] + gosia[1] * adam[2] + gosia[2] * adam[0];
    if(a > b) cout << "ADAM\n";
    else if(a < b) cout << "GOSIA\n";
    else cout << "=\n";
  }
}