#include <bits/stdc++.h>
using namespace std;

string s;
int stage;

int getNum(string str){
  int num = 1;
  for(auto s : str) num *= s - '0';
  return num;
}

int main(){
  cin >> s;

  while(1){
    if(s.size() == 1) break;
    stage++;
    int num = getNum(s);
    s = to_string(num);
  }

  cout << stage;
}