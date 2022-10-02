#include <bits/stdc++.h>
using namespace std;
string name;
int t, score;

string getGrade(int score){
  if(score >= 97) return "A+";
  if(90 <= score && score <= 96) return "A";
  if(87 <= score && score <= 89) return "B+";
  if(80 <= score && score <= 86) return "B";
  if(77 <= score && score <= 79) return "C+";
  if(70 <= score && score <= 76) return "C";
  if(67 <= score && score <= 69) return "D+";
  if(60 <= score && score <= 66) return "D";
  return "F";
}

int main(){
  cin >> t;
  while(t--){
    cin >> name >> score;
    cout << name << ' ' << getGrade(score) << '\n';
  }
}