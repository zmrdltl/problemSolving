#include <bits/stdc++.h>
using namespace std;

string s;
int a, b;

int main(){
  cin >> s;
  for(int i = 0; i < s.size(); i+=2){
    if(s[i] == 'A') a += s[i+1] - '0';
    else b += s[i+1] - '0';
  }
  if(a > b) cout << "A";
  else cout << "B";
}