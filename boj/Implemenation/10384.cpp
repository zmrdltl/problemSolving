#include <bits/stdc++.h>
using namespace std;

string getFilteredStr(string s){
  string str;
  for(auto c : s){
    if('A' <= c && c <= 'Z') str += c - 'A' + 'a';
    else if('a' <= c && c <= 'z') str += c;
  }
  return str;
}

string getResultStr(string s){
  int pangramCnt = 10;
  vector <int> alpha(26,0);
  string str = getFilteredStr(s);
  for(auto c : str){
    alpha[c-'a']++;
  }

  for(int i = 0; i < 26; i++){
    pangramCnt = min(pangramCnt, alpha[i]);
  }

  if(!pangramCnt) return "Not a pangram\n";
  if(pangramCnt == 1) return "Pangram!\n";
  if(pangramCnt == 2) return "Double pangram!!\n";
  return "Triple pangram!!!\n";
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