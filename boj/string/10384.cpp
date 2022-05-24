#include <bits/stdc++.h>
using namespace std;

string getResultStr(string s){
  int pengramCnt = 10;
  vector <int> alpha(26,0);
  string str = getFilteredStr(s);
  for(auto c : str){
    alpha[c-'a']++;
  }

  for(int i = 0; i < 26; i++){
    pengramCnt = min(pengramCnt, alpha[i]);
  }

  if(!pengramCnt) return "Not a pangram\n";
  if(pengramCnt == 1) return "Pangram!\n";
  if(pengramCnt == 2) return "Double pangram!!\n";
  return "Triple pangram!!!\n";
}

string getFilteredStr(string s){
  string str;
  for(auto c : s){
    if('A' <= c && c <= 'Z') str += c - 'A' + 'a';
    else if('a' <= c && c <= 'z') str += c;
  }
  return str;
}

int main(){
  int t;
  string s;

  cin >> t;
  cin.ignore();

  for(int testCase = 1; testCase <= t; testCase++){
    getline(cin,s);
    cout << "Case " << testCase << ": " << getResultStr(s);
  }
}