#include <bits/stdc++.h>
using namespace std;

string s, vowel = "aeiou";
int n, ans;

bool hasVowel(char c) {
  for(auto v : vowel)
    if(v == c)
      return true;
  return false;
}

int main(){
  cin >> n >> s;
  for(int i = 0; i < n; i++){
    if(hasVowel(s[i])) 
      ans++;
  }
  cout << ans;
}