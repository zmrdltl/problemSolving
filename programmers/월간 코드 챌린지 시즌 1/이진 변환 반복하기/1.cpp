#include <bits/stdc++.h>
using namespace std;
int converted, deleted;
string deleteZero(string s){
  string deletedStr;
  for(auto c : s) {
    if(c != '0') deletedStr += c;
    else deleted++;
  }
  return deletedStr;
}

string convertToBin(string s){
  int num = s.size();
  converted++;
  string convertedStr;
  while(num){
    convertedStr += to_string(num % 2);
    num /= 2;
  }
  reverse(convertedStr.begin(), convertedStr.end());
  return convertedStr;
}

vector<int> solution(string s) {
    converted = 0;
    deleted = 0;
    string str = s;
    while(1){
      if(str == "1") break;
      str = deleteZero(str);
      str = convertToBin(str);
    }
    return {converted, deleted};
}