#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
  cin >> s;
  for(auto &c : s) c = c - 'a' + 'A';
  cout << s;
}