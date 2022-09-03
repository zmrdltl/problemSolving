#include <bits/stdc++.h>
using namespace std;

vector <string> clickedInfo;
int coin[4] = {0, 500, 800, 1000}, sum;
string s;

vector <string> split(string input, char delimiter){
    vector <string> result;
    stringstream ss(input);
    string tmp;

    while(getline(ss,tmp,delimiter)) result.push_back(tmp);
    return result;
}

int main(){
  getline(cin, s);
  clickedInfo = split(s, ' ');
  for(auto c : clickedInfo){
    sum += coin[stoi(c)];
  }
  cout << 5000 - sum;
}