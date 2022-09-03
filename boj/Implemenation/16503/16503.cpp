#include <bits/stdc++.h>
using namespace std;

string s;
vector <string> expr, op;
int res1, res2;

vector <string> split(string input, char delimiter){
    vector <string> result;
    stringstream ss(input);
    string tmp;

    while(getline(ss,tmp,delimiter)) result.push_back(tmp);
    return result;
}

int getRes(string sa, string op, string sb){
  int a = stoi(sa), b = stoi(sb);
  if(op == "+") return a + b;
  if(op == "-") return a - b;
  if(op == "*") return a * b;
  return a / b;
}

int main(){
  getline(cin, s);
  expr = split(s, ' ');

  res1 = getRes(expr[0], expr[1], expr[2]);
  res1 = getRes(to_string(res1), expr[3], expr[4]);

  res2 = getRes(expr[2], expr[3], expr[4]);
  res2 = getRes(expr[0], expr[1], to_string(res2));

  cout << min(res1, res2) << '\n' << max(res1, res2);
}