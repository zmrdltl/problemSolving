#include <bits/stdc++.h>
using namespace std;
long long n, sum;
string s, tmp;
int main(){
  cin >> n;
  cin >> s;
  for(int i = 0; i < s.size(); i++){
    if('0' <= s[i] && s[i] <= '9'){
      tmp += s[i];
    }
    if(s[i] < '0' || s[i] > '9' || i == s.size() -1 ){
      if(tmp.size()){
        sum += stoi(tmp);
        tmp = "";
      }
    }
  }
  cout << sum <<'\n';
}